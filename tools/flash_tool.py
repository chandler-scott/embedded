#!/usr/bin/env python3
import argparse
import subprocess
import sys

# Description: <DESCRIPTION>
# Author: Chandler Scott (scottcd1@etsu.edu)
# Date: 04/30/24 
# License: GNU General Public License v3.0

def main():
    parser = argparse.ArgumentParser(description='Flash tool script to upload binaries to the microcontroller with specified port')
    parser.add_argument('-b', '--binary', type=str, required=True, help='Path to binary file')
    parser.add_argument('-p', '--port', type=str, default="/dev/ttyACM0", help='Port to upload to')

    args = parser.parse_args()

    # Configuration for AVRDUDE
    mcu = "atmega328p"              # Adjust MCU type according to your target
    programmer = "arduino"          # Adjust programmer type
    baud = 115200                   # Adjust baud rate as necessary

    print(f"Flashing the binary: {args.binary} on port {args.port}")
    try:
        subprocess.run(['avrdude', '-p', mcu, '-c', programmer, '-P', args.port, '-b', str(baud), '-D', '-U', f'flash:w:build/{args.binary}:i'],
                       check=True)
    except subprocess.CalledProcessError as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    main()

