#!/bin/bash
wget -P .. https://raw.githubusercontent.com/thisisteey/alx-low_level_programming/master/0x18-dynamic_libraries/libgigtest.so
export LD_PRELOAD="$PWD/../libgigtest.so"
