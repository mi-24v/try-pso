#!/bin/bash

mkdir -p optim_build/lib
cd ./optim
./configure -i "../optim_build" -p
make -j9 && make install
cd ..
