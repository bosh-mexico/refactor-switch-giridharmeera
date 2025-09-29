cmake_minimum_required(VERSION 3.14)
project(PaymentProcessorLib VERSION 1.0 LANGUAGES CXX)

# -----------------------------
# C++ Standard
# -----------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------
# Include directories
# -----------------------------
include_directories("${PROJECT_SOURCE_DIR}/include")

# -----------------------------
# Collect all library source files
# -----------------------------
file(GLOB_RECURSE LIB_SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

# Debug: print found sources
message(STATUS "Library source files:")
foreach(src_file ${LIB_SOURCES})
    message(STATUS "  ${src_file}")
endforeach()

# Fail early if no sources found
if(NOT LIB_SOURCES)
    message(FATAL_ERROR "No source files found in src/. Make sure .cpp files exist.")
endif()

# -----------------------------
# Build the static library
# -----------------------------
add_library(PaymentProcessorLib STATIC ${LIB_SOURCES})

# -----------------------------
# Build demo executable from app/main.cpp
# -----------------------------
set(APP_SOURCES "${PROJECT_SOURCE_DIR}/app/main.cpp")

if(EXISTS ${APP_SOURCES})
    add_executable(PaymentDemo ${APP_SOURCES})
    target_link_libraries(PaymentDemo PRIVATE PaymentProcessorLib)
    target_include_directories(PaymentDemo PRIVATE include)
else()
    message(WARNING "No main.cpp found in app/. Skipping demo executable build.")
endif()

# -----------------------------
# Optional: install targets
# -----------------------------
install(TARGETS PaymentProcessorLib DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)
