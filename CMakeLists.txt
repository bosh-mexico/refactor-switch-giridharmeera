cmake_minimum_required(VERSION 3.15)
project(PaymentDemo)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Library sources
set(LIB_SOURCES
    src/PayPalProcessor.cpp
    src/GooglePayProcessor.cpp
    src/CreditCardProcessor.cpp
    src/PaymentProcessorFactory.cpp
)

# Build static library
add_library(PaymentProcessorLib ${LIB_SOURCES})

# Build executable
add_executable(PaymentDemo app/main.cpp)

# Link library
target_link_libraries(PaymentDemo PaymentProcessorLib)
