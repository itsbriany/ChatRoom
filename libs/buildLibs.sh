#!/bin/bash

DIR=$(pwd)

# A quick script to prepare the libraries
git clone https://github.com/boostorg/boost.git
git submodule init
git submodule update

# Install b2
cd $DIR/boost
./bootstrap.sh

# Now run ./b2 --show-libraries to see libraries that can be installed
# Run ./b2 --with-<library> to install the library
./b2 --with-system

# Cleanup
cd ..
mv bootstrap.log boost/
