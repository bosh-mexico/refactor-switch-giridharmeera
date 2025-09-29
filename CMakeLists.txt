cmake_minimum_required(VERSION 3.14)
project(PaymentProcessorLib VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include headers for installation
include_directories(include)

# Source files
file(GLOB SOURCES "src/*.cpp")

# Create static library
add_library(PaymentProcessorLib STATIC ${SOURCES})

# Optionally, define where to install
install(TARGETS PaymentProcessorLib DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)
