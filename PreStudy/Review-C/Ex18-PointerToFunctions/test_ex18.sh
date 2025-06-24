#!/bin/bash
set -e

make

valgrind -q --leak-check=full ./ex18 4 1 7 3 2 0 8
