#!/usr/bin/env bash

mkdir ../build
cd ../build
mkdir coverage
touch coverage/lcov.info
cmake ..
make
./tests
