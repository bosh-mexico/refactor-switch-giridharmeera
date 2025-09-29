cmake_minimum_required(VERSION 3.14)
project(PaymentProcessorLib VERSION 1.0 LANGUAGES CXX)

# -----------------------------
# C++ standard
# -----------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------
# Include directories (public)
# -----------------------------
include_directories("${PROJECT_SOURCE_DIR}/include")

# -----------------------------
# Collect all source files
# -----------------------------
file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

# -----------------------------
# Debug: print found sources
# -----------------------------
message(STATUS "Found source files:")
foreach(src_file ${SOURCES})
    message(STATUS "  ${src_file}")
endforeach()

# -----------------------------
# Fail early if no sources found
# -----------------------------
if(NOT SOURCES)
    message(FATAL_ERROR "No source files found in src/. Make sure .cpp files exist.")
endif()

# -----------------------------
# Build static library
# -----------------------------
add_library(PaymentProcessorLib STATIC ${SOURCES})

# -----------------------------
# Optional: Install targets
# -----------------------------
install(TARGETS PaymentProcessorLib DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)
