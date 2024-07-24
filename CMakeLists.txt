cmake_minimum_required(VERSION 3.20)

# Project Name and Language
project(Conpyrus CXX) # Specify CXX for C++ project

# Set C++ standard
set(CMAKE_CXX_STANDARD 11) # Set to C++11; adjust if needed
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable
add_executable(Conpyrus src/main.cpp src/conpy.cpp src/conpyrus.cpp) # Change to .cpp if using C++ source files

# Specify include directories
target_include_directories(Conpyrus PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Optionally add compile options or definitions
# target_compile_options(Conpyrus PRIVATE -Wall -Wextra)

# Optionally link libraries or other targets
# target_link_libraries(Conpyrus PRIVATE some_library)

# Add a test executable (if needed)
# add_executable(ConpyrusTests tests/test_main.cpp) # Change to .cpp for C++ tests

# Link test executable with the main target
# target_link_libraries(ConpyrusTests PRIVATE Conpyrus)

# Enable testing and add tests (if needed)
# enable_testing()
# add_test(NAME ConpyrusTests COMMAND ConpyrusTests)
