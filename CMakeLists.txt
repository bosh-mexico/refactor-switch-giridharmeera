cmake_minimum_required(VERSION 3.14)
project(PaymentProcessorApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
file(GLOB SRC_FILES src/*.cpp)

# Include directories
include_directories(include)

# Library sources
set(LIB_SOURCES
    src/PayPalProcessor.cpp
    src/GooglePayProcessor.cpp
    src/CreditCardProcessor.cpp
    src/PaymentProcessorFactory.cpp
)

# Main executable
add_executable(payment_app app/main.cpp ${SRC_FILES})
target_include_directories(payment_app PRIVATE include)

# GoogleTest
enable_testing()
find_package(GTest REQUIRED)

# Test executable
file(GLOB TEST_FILES test/*.cpp)
add_executable(payment_tests ${TEST_FILES} ${SRC_FILES})
target_include_directories(payment_tests PRIVATE include)

target_link_libraries(payment_tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(payment_tests)
