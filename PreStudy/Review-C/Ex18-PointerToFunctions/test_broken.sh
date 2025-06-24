#!/bin/bash
set -e

make broken

valgrind -q --leak-check=full ./broken 4 1 7 3 2 0 8
