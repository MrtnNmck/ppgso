PPGSO OpenGL Examples
----

This repository contains simple OpenGL 3.3 examples for educational purposes.

All examples are written in C++11 and use Makefiles AND [CMake build system](http://cmake.org). Additionally the following dependencies are required:

* [GLEW][1]
* [GLFW3][2]
* [GLM][3]

On Linux install the following dependencies using your package manager, for example on Ubuntu do:

```bash
sudo apt-get install libglew-dev libglfw3-dev libglm-dev
```

On OSX install [Homebrew][4] package manager and install

```bash
brew tap homebrew/versions
brew install glm glfw3 glew
```

Additionally you can also install CMake and use it to generate project files for your IDE of choice.

Building using make
----

Recommended for OSX and Linux is to simply use make. For Windows see next section.

```bash
cd ppgso-master
make
./gl_gradient
```

Building and working on Windows
----

Windows is a special case as always, however it is a lot easier if you avoid Visual Studio entirely. The recommended software is as follows:

* Download and install [TDM64][5], this is the latest GCC compiler for Windows in a nice installer.
* Download [CLion IDE][6], the trial is free for 30days and you can register for a FREE COPY using university mail.
* Run CLion and select TDM64 as the toolchain (default is C:/TDM64..)
* Setup the rest of the settings as you see fit.
* Open this directory as an existing project, the examples should now build.
* For some examples you need to set working directory to the project folder as well.

A good alternative IDE for Windows is [QTCreator][7] that should work out of the box with TDM64 and CMake. For other IDEs see below.

Common pitfalls
---
* NEVER store projects in paths and directories that contain spaces or non-ascii characters.
* If you are unfortunate enough to have a username with non-ascii characters builds will fail unless you edit CLion configuration manually.

```
# Edit idea.properties file in CLion install directory and add
idea.system.path=C:/clion/system
# Make sure the directory exists
```

* Ubuntu 14.04 based distributions do not have GLFW3!
  * Install [libglfw3 deb][8] then install [libglfw3-dev][9] 

* My linux does not have OpenGL. Missing -lGL
  * Try to install `mesa-common-dev`, `libgl1-mesa-dev` and `libglu1-mesa-dev`

Generic instructions using CMake, should work with Visual Studio
----

Using CMake from command-line you can generate the project files as shown below. The placeholder [YOUR_GENERATOR] should be replaced with the generator appropriate for your IDE/environment. Usually removing the option entirely will generate the default for the given platform. To find out all available generators just run `cmake --help`

```bash
cd ppgso
mkdir _build && cd _build
cmake .. -G[YOUR_GENERATOR] -DCMAKE_INSTALL_PREFIX=../_install
cmake --build . --target install
```

When building on Windows CMake might not be able to automatically find all the needed dependencies and will require additional pointers. This is done by setting CMake variables such as GLEW_INCLUDE_DIRS which should point to the headers of the GLEW library that you want to use. Same principle applies for other dependencies. You can alternatively use CMake GUI and point it to the work directory, it will allow you to edit the variables more comfortably.

```bash
cd ppgso/_build
cmake .. -DGLFW_INCLUDE_DIRS="C:\libs\glfw3\include" -DGLFW_LIBRARIES="C:\libs\glfw3\glfw3.dll" -DGLEW_INCLUDE_DIRS=...
cmake --build . --target install
```


After installation the files should be installed into a new `_install` subdirectory. You can then run the examples as follows:

```bash
cd ppgso/_install
./gl_gradient
```

[1]: http://glew.sourceforge.net
[2]: http://www.glfw.org
[3]: http://glm.g-truc.net
[4]: http://brew.sh
[5]: http://tdm-gcc.tdragon.net
[6]: https://www.jetbrains.com/clion/
[7]: http://www.qt.io/ide/
[8]: http://launchpadlibrarian.net/173940430/libglfw3_3.0.4-1_amd64.deb
[9]: http://launchpadlibrarian.net/173940431/libglfw3-dev_3.0.4-1_amd64.deb
