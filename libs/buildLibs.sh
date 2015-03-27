#!/bin/bash

DIR=$(pwd)

# A quick script to prepare the libraries
git clone https://github.com/boostorg/boost.git
cd $DIR/boost
git submodule init
git submodule update

# Install b2
./bootstrap.sh

# Now run ./b2 --show-libraries to see libraries that can be installed
# Run ./b2 --with-<library> to install the library
./b2 --with-system

cd $DIR



../libs/asio/include/boost/asio/
