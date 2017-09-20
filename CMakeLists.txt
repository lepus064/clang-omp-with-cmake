cmake_minimum_required(VERSION 3.4.3)
project(omptest)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader )

include_directories( ${LLVM_INCLUDE_DIRS})

set(CMAKE_C_COMPILER   /usr/local/opt/llvm/bin/clang)
set(CMAKE_CXX_COMPILER /usr/local/opt/llvm/bin/clang++)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

# Now build our tools
add_executable(omptest omptest.cpp)

# Link against LLVM libraries
target_link_libraries(omptest ${llvm_libs} /usr/local/opt/llvm/lib/libomp.dylib )
