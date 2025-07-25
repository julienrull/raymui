# RAYMUI

A personal implementation of [rxi's microui](https://github.com/rxi/microui) for [raysan's raylib](https://github.com/raysan5/raylib).

## Features

* ***Bundle into a single header library.***
* Or include the source files directly in your project build.

## Usage

### Single Header

The `src` folder contains the standard `raymui.h` without implementation.
To generate the single header library, run:

```sh
./build.sh
```

Just include the header and declare the implementation in your project’s entry point like so:

```c
// file: main.c
#include <raylib.h>
// ...
#define RAYMUI_IMPLEMENTATION
#include <raymui.h>
```

### From Source

Use the standard `microui.h` and `raymui.h` in any source file where needed:

```c
#include <raylib.h>
// ...
#include <microui.h>
#include <raymui.h>
```

Add the library source files to your build command like this:

```sh
# Example with gcc
gcc -std=c99 -Wall -Werror your_entry_point.c microui.c raymui.c -o your_app -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```
