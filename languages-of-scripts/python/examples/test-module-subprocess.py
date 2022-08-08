#!/usr/bin/env python3

import subprocess


def run_command(cmd):
    process = subprocess.run(cmd)
    try: 
        process.check_returncode()
    except SubprocessError as err:
        print("run command: \""process.cmd+" has some error:\n")
        print("-------- Run Command Expresption Message -------")
        print(err)

    





if __name__ == "__main__":
    print("run in __main__")
    cmd = ("sudo", "ls", "-l")
    run_command(cmd)
