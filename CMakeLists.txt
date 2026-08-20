cmake_minimum_required(VERSION 4.0.0 )
project(ohmic)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED 23)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add all implementation files
set(SOURCES
    src/calculator.cpp
    src/ohmic.cpp
    main.cpp
)
#
# Define the executable target
add_executable(ohmic ${SOURCES})

# Include headers directory
target_include_directories(ohmic PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

# Standard compiler warnings
if(MSVC)
  target_compile_options(ohmic PRIVATE /W4)
else()
  target_compile_options(ohmic PRIVATE -Wall -Wextra -Wpedantic)
endif()
