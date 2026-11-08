cmake_minimum_required(VERSION 4.2)
project(lotus_core C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../libs")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../libs")
add_library(lotus_core SHARED
        library.c
        src/io.c
        src/conversion.c
        src/random.c
        internal/string_runtime.c
        utils/string_utils.c)
target_include_directories(lotus_core PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
