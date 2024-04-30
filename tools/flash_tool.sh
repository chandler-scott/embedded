#!/bin/bash

# Description: <DESCRIPTION>
# Author: Chandler Scott (scottcd1@etsu.edu)
# Date: 04/30/24 
# License: GNU General Public License v3.0

#!/bin/bash

# Flash tool script to upload binaries to the microcontroller with specified port

function usage {
    echo "Usage: $0 -b <binary_path> -p <port>"
    exit 1
}

if [ "$#" -ne 4 ]; then
    usage
fi

while getopts ":b:p:" opt; do
    case ${opt} in
        b )
            BINARY=$OPTARG
            ;;
        p )
            PORT=$OPTARG
            ;;
        \? )
            echo "Invalid option: $OPTARG" 1>&2
            usage
            ;;
        : )
            echo "Invalid option: $OPTARG requires an argument" 1>&2
            usage
            ;;
    esac
done
shift $((OPTIND -1))

if [ -z "${BINARY}" ] || [ -z "${PORT}" ]; then
    usage
fi

# Configuration for AVRDUDE
MCU="atmega328p"               # Adjust MCU type according to your target
PROGRAMMER="arduino"           # Adjust programmer type
BAUD=115200                    # Adjust baud rate as necessary

echo "Flashing the binary: $BINARY on port $PORT"
avrdude -p $MCU -c $PROGRAMMER -P $PORT -b $BAUD -D -U flash:w:$EMBEDDED_BUILD_DIR/$BINARY:i

