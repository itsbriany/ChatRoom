#!/bin/bash

# A quick script to prepare the libraries
git clone https://github.com/boostorg/boost.git
cd boost
git submodule init
git submodule update
./booststrap.sh
# Now run ./b2 --show-libraries to see libraries that can be installed
# Run ./b2 --with-<library> to install the library


