cmake_minimum_required(VERSION 3.15)

project(DJConsole
    VERSION 1.0
    LANGUAGES C
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(Options)
include(CompilerFlags)
include(Sanitizers)

add_subdirectory(src)