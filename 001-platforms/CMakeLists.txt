cmake_minimum_required(VERSION 2.8)

# Project
project(001)

# OpenCL package
find_package(OpenCL REQUIRED)

# Directories
set(example_BIN_DIR bin)
set(example_INC_DIR include)
set(example_LIB_DIR lib)
set(example_SRC_DIR src)

# Files
set(executable_SOURCES ${example_SRC_DIR}/main.cpp)

# Add executable to project
add_executable(executable ${executable_SOURCES})

# Linking
target_link_libraries(executable PRIVATE ${OpenCL_LIBRARIES})

# Install
install(TARGETS executable DESTINATION ${example_BIN_DIR})
