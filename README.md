# VisualSortAlgorithm

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for install instructions](https://cmake.org/install/)

* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for install instructions](http://gnuwin32.sourceforge.net/packages/make.htm)

* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 

* SDL_tff >= 3.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/SDL2/Installation), project source can be found [here](https://github.com/libsdl-org/SDL_ttf)

* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions Windows
1. Clone: this repo localy.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run: `./VisualSortAlgo`.

## Basic Build Instructions macOS
0. Install SDL TFF: "brew install sdl_ttf"
1. Clone: this repo localy.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run: `./VisualSortAlgo`.

## Basic Build Instructions linux
0. Install SDL TFF: 
    "git clone https://github.com/libsdl-org/SDL.git -b SDL2"
    "cd SDL"
    "mkdir build"
    "cd build"
    "make"
    "sudo make install"
1. Clone: this repo localy.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run: `./VisualSortAlgo`.