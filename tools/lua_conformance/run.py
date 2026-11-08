"""Run the Lua conformance probes against one dinput8.dll and write a report.

The report is the input to diff.py. Two runs -- one on the hand-written
bindings, one on the sol2 baseline -- diffed, are the gate a binding change has
to pass: any line that differs is a semantic divergence, which is the class
neither the compiler nor a grep can catch.

    python tools/lua_conformance/run.py --dll build/dinput8.dll --out /tmp/hand.txt
    python tools/lua_conformance/run.py --dll dinput8.dll_bak_sol2 --out /tmp/sol2.txt
    python tools/lua_conformance/diff.py /tmp/sol2.txt /tmp/hand.txt

The game is restarted for the run and left running on the dll that was passed,
so a second run picks up from there.
"""
import argparse
import importlib.util
import os
import shutil
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
REPO = HERE.parent.parent
PROBES = HERE / "probes"


def load_rpc_client():
    path = REPO / "docs" / "lua_rpc" / "lua.py"
    spec = importlib.util.spec_from_file_location("lua_rpc_client", path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def kill_game(image="re4.exe"):
    subprocess.run(["taskkill", "/IM", image, "/F"],
                   capture_output=True, text=True)


def launch(game_dir):
    exe = game_dir / "re4.exe"

    if not exe.exists():
        sys.exit("no re4.exe in %s" % game_dir)

    # start is a cmd builtin; it returns before the game finishes loading.
    subprocess.run(["cmd", "/c", "start", "", str(exe)], cwd=str(game_dir),
                   capture_output=True, text=True)


def install_dll(game_dir, dll):
    target = game_dir / "dinput8.dll"

    if target.exists():
        backup = game_dir / ("dinput8.dll_bak_%s" % time.strftime("%Y%m%d%H%M%S"))
        shutil.move(str(target), str(backup))
        print("backed up the installed dll as %s" % backup.name)

    shutil.copyfile(str(dll), str(target))
    print("installed %s" % dll)


def wait_for_rpc(client, seconds, port):
    deadline = time.time() + seconds
    attempt = 0

    while time.time() < deadline:
        attempt += 1
        reply = client.lua("return 1", port=port)

        if reply.get("ok"):
            print("rpc ready after %d s" % int(seconds - (deadline - time.time())))
            return

        time.sleep(3)

    sys.exit("rpc did not answer within %d s" % seconds)


def run_probe(client, prelude, body, port):
    reply = client.lua(prelude + "\n" + body, port=port, timeout_ms=20000)

    if not reply.get("ok"):
        return ["!! probe failed: %s" % reply.get("error", "no error given")]

    lines = reply.get("returns") or []

    if len(lines) != 1 or not isinstance(lines[0], str):
        return ["!! unexpected reply: %r" % (reply,)]

    return lines[0].split("\n")


def main():
    p = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    p.add_argument("--dll", required=True, help="dinput8.dll to test")
    p.add_argument("--out", required=True, help="report file to write")
    p.add_argument("--game-dir", default=r"D:\Games\Resident Evil 4",
                   help="install directory holding re4.exe")
    p.add_argument("--port", type=int, default=13377)
    p.add_argument("--wait", type=int, default=180, help="seconds to wait for rpc")
    p.add_argument("--no-launch", action="store_true",
                   help="use the game already running instead of installing and starting it")
    p.add_argument("--only", action="append",
                   help="run just this probe (repeatable), e.g. 02_plumbing.lua")
    args = p.parse_args()

    dll = Path(args.dll).resolve()
    game_dir = Path(args.game_dir)
    client = load_rpc_client()

    if not args.no_launch:
        kill_game()
        time.sleep(7)
        install_dll(game_dir, dll)
        launch(game_dir)
        wait_for_rpc(client, args.wait, args.port)

    prelude = (PROBES / "_prelude.lua").read_text(encoding="utf-8")
    probes = sorted(PROBES.glob("[0-9][0-9]_*.lua"))

    if args.only:
        wanted = set(args.only)
        probes = [p for p in probes if p.name in wanted]

    out = []

    for probe in probes:
        out.append("### %s" % probe.name)
        out.extend(run_probe(client, prelude, probe.read_text(encoding="utf-8"), args.port))
        out.append("")
        print("ran %s" % probe.name)

    Path(args.out).write_text("\n".join(out), encoding="utf-8", newline="\n")
    print("wrote %s (%d lines)" % (args.out, len(out)))


if __name__ == "__main__":
    main()