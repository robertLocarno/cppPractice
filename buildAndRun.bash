#!/bin/bash

set -euo pipefail

bar=$(printf '\342\224\203') # U+2503

echo -e "Building..."

mkdir -p ./build/$(dirname $1)

g++ $1.cpp -o ./build/"$1" -std=c++20 2>&1 | sed "s/^/$bar  /"

echo -e "Build Done\r\n"

echo -e "Running..."
./build/$1 | sed "s/^/$bar  /"
echo -e "Run complete"
