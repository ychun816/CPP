#!/bin/bash

if [ $# -gt 0 ] && [ $1 = "clean" ]; then
    for ((i = 0; i < 4; i++)); do
        make -C ex0$i fclean
    done
    # rm -rf *.o *.out *.exe
else
    for((i = 0; i < 4; i++)); do
        make -C ex0$i
    done
fi