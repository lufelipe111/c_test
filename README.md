# Instructions to build and run C programs on docker

## Building and compiling
  1. paste all your program in main.c file
  2. on command prompt change directory to the main.c directory running: cd _PATH_
  3. run on command prompt: _docker build -t my-gcc-app ._

## Running your app
  1. run on command prompt: _docker run -it --rm --name my-running-app my-gcc-app_

## Notes
  * Everytime you change main.c file you need to build my-gcc-app before run it