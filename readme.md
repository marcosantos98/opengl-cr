# OpenGL + GLFW Hotreload template

Basic opengl template that can be hotreloaded. This works using a C++ header from [fungos](https://github.com/fungos).

## Requirements:

- Cmake
- C++ compilers
- GLFW headers and compiled lib
- GLAD headers and implementation
- CR header from [Fungo](https://github.com/fungo)

## Build:

### Setup GLFW and GLAD

- On Windows or MAC, you can download the compiled binaries from [GLFW website](https://www.glfw.org/) and place the libraries in `third/glfw/libs` and the header files in `third/glfw`. On other OS you need to build GLFW from scratch and place the libraries and headers in the same folders. 
- To setup GLAD you only need to generate the bindings using the author [website](https://glad.dav1d.de/) and place the generated files in `third/glad` and rename `glad.c to glad.cpp`.
- [Fungo/cr](https://github.com/fungo/cr) is a header only file that you only need to download and place in `third/cr`.

### Actual build:

```cmd
cmake -B build
cmake --build build
```
## Licenses

This code written by me is under MIT, for GLFW, GLAD and CR, check the correspoding porjects to check their LICENSE.