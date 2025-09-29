cmake_minimum_required(VERSION 3.14)
project(PaymentProcessorDemo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main library
add_library(payment_processors
    src/PayPalProcessor.cpp
    src/GooglePayProcessor.cpp
    src/CreditCardProcessor.cpp
    src/PaymentProcessorFactory.cpp
)

target_include_directories(payment_processors PUBLIC include)

# Application
add_executable(payment_app app/main.cpp)
target_link_libraries(payment_app PRIVATE payment_processors)

# ---- GoogleTest ----
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: Prevent overriding parent project’s compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Unit tests
add_executable(payment_tests tests/PaymentProcessorTest.cpp)
target_link_libraries(payment_tests PRIVATE payment_processors gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(payment_tests)
