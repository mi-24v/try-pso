## try-pso

An practice of Particle Swarm Optimization(PSO)

## Requirements

* cmake
* [Armadillo](http://arma.sourceforge.net/)

## Usage

This is manual way : cmake configure, generate and build was done by VSCode commands in my environment.

```sh
#setup
git submodule update -i
export ARMA_INCLUDE_PATH=/path/to/armadillo_bits
./setup.sh
#make
mkdir build
cd build
cmake ..
cd ..
cmake --build ./build --config Debug --target all -- -j 10
#run
./build/main
```
