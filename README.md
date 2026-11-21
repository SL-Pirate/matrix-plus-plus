# matrix++

Matrix-style digital rain for the terminal, written in C++ with ncurses.

## Requirements

- CMake 4.0+
- Conan 2
- A C++17 compiler

## Build

```sh
conan install . --build=missing
cmake --preset conan-release
cmake --build --preset conan-release
```

## Run

```sh
./build/Release/matrix++
```

Press `Ctrl+C` to quit.

## FAQ

### `ncurses: cannot initialize terminal type ($TERM="xterm-256color"); exiting`

The Conan build of ncurses does not look in the system terminfo directory. Point it there:

```sh
TERMINFO_DIRS=/usr/share/terminfo ./build/Release/matrix++
```
