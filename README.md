# DJ Console Software

A DJ console application for Linux Ubuntu, currently under active development. This project is being built as a learning exercise with plans to integrate machine learning capabilities in the future.

## Overview

This software aims to provide a functional DJ console interface with audio mixing and playback capabilities. The project is in its early stages, focusing on establishing the core UI framework and system architecture.

## Building the Project

### Prerequisites

- GCC (**13.1.0**)
- CMake (**3.15** or higher)
- Linux (**Ubuntu 22.04.5 LTS**)

### Build Instructions

```bash
# Clone the repository
git clone https://github.com/panagiotisTeas/DJController.git
cd DJController

# Create build directory
mkdir build
cd build

# Generate build files and compile
cmake ..
make

# Run the application
./src/dj_console
```

## Dependencies

Raylib is statically linked (*no external installation needed*)

## Purpose

This project is developed for educational purposes, exploring:

- Low-level systems programming in C
- Real-time audio processing and mixing
- Multimedia application development with Raylib
- Exploring machine learning integration in audio software

## License

This project is licensed under the [MIT License](LICENSE)