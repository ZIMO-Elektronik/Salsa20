cmake_minimum_required(VERSION 3.19 FATAL_ERROR)
include(FetchContent)

FetchContent_Declare(
  CMakeModules
  GIT_REPOSITORY https://github.com/ZIMO-Elektronik/CMakeModules.git
  GIT_TAG v0.0.1
  SOURCE_DIR ${CMAKE_BINARY_DIR}/CMakeModules)
FetchContent_MakeAvailable(CMakeModules)

project(
  Salsa20
  VERSION 0.3.0
  LANGUAGES C CXX)

add_library(Salsa20 STATIC src/salsa20.c)
add_library(Salsa20::Salsa20 ALIAS Salsa20)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  target_include_directories(
    Salsa20
    INTERFACE include
    PRIVATE include/salsa20)
else()
  target_include_directories(
    Salsa20 SYSTEM
    INTERFACE include
    PRIVATE include/salsa20)
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include(CTest)
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
  add_subdirectory(tests)
endif()
