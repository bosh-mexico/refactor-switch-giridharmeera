cmake_minimum_required(VERSION 3.14)
project(PaymentProcessorProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------
# Library for Payment Processors
# -----------------------------
file(GLOB SRC_FILES Payment_processor/*.cpp)

add_library(payment_processors ${SRC_FILES})
target_include_directories(payment_processors PUBLIC include)

# -----------------------------
# Main Executable
# -----------------------------
add_executable(payment_app Payment_app/main.cpp)
target_link_libraries(payment_app PRIVATE payment_processors)

# -----------------------------
# GoogleTest Setup
# -----------------------------
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # for Windows
FetchContent_MakeAvailable(googletest)

enable_testing()

# -----------------------------
# Unit Tests
# -----------------------------
add_executable(payment_tests test/PaymentProcessorTest.cpp)
target_link_libraries(payment_tests PRIVATE payment_processors gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(payment_tests)
