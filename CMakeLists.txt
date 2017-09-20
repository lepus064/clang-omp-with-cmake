cmake_minimum_required(VERSION 3.4.3)
project(omptest)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

# Set your project compile flags.
# E.g. if using the C++ header files
# you will need to enable C++11 support
# for your compiler.

message("DIR ${LLVM_INCLUDE_DIRS}")


# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader )
message("lib ${llvm_libs}")
include_directories( ${LLVM_INCLUDE_DIRS})

set(CMAKE_C_COMPILER   /usr/local/opt/llvm/bin/clang)
set(CMAKE_CXX_COMPILER /usr/local/opt/llvm/bin/clang++)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
# set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-L/usr/local/opt/llvm/lib -Wl,-rpath,/usr/local/opt/llvm/lib")

#${LLVM_INCLUDE_DIRS}
# add_definitions(${LLVM_DEFINITIONS})

# Now build our tools
add_executable(omptest omptest.cpp)

# Link against LLVM libraries
target_link_libraries(omptest ${llvm_libs} /usr/local/opt/llvm/lib/libiomp5.dylib /usr/local/opt/llvm/lib/libomp.dylib )
