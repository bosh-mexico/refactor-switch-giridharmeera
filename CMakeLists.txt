cmake_minimum_required(VERSION 3.15)
project(PaymentProcessorProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include headers
include_directories(include)

# Source files
set(SRC_FILES
    src/CreditCardProcessor.cpp
    src/GooglePayProcessor.cpp
    src/PayPalProcessor.cpp
    src/PaymentProcessorFactory.cpp
)

# Build library
add_library(PaymentProcessorLib STATIC ${SRC_FILES})

# Build demo executable
add_executable(PaymentDemo app/main.cpp)
target_link_libraries(PaymentDemo PRIVATE PaymentProcessorLib)
