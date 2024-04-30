#!/bin/bash

# Description: <DESCRIPTION>
# Author: Chandler Scott (scottcd1@etsu.edu)
# Date: 04/30/24 
# License: GNU General Public License v3.0

#!/bin/bash

# Build tool script to compile specific or all binaries


if [ "$#" -eq 0 ]; then
  echo "Building all projects..."
  (cd $EMBEDDED_SRC_DIR && make clean && make)  # Builds all projects
else
  echo "Building project: $1"
  (cd $EMBEDDED_SRC_DIR && make $1)  # Builds a specific project based on the argument
fi

