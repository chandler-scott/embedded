#!/usr/bin/env python3
import argparse
import subprocess
import os
import sys

# Description: <DESCRIPTION>
# Author: Chandler Scott (scottcd1@etsu.edu)
# Date: 04/30/24 
# License: GNU General Public License v3.0

def main():
    parser = argparse.ArgumentParser(description='Build tool script to compile specific or all binaries')
    parser.add_argument('project', nargs='?', help='Specific project name to build, builds all if not specified')

    args = parser.parse_args()

    embedded_src_dir = os.getenv('EMBEDDED_SRC_DIR')
    if not embedded_src_dir:
        print("Error: EMBEDDED_SRC_DIR environment variable is not set.", file=sys.stderr)
        sys.exit(1)

    if args.project:
        print(f"Building project: {args.project}")
        command = ['make', args.project]
    else:
        print("Building all projects...")
        command = ['make', 'clean', '&&', 'make']

    try:
        subprocess.run(command, cwd=embedded_src_dir, check=True, shell=True)
    except subprocess.CalledProcessError as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    main()

