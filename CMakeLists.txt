cmake_minimum_required(VERSION 3.25 FATAL_ERROR)
include(FetchContent)

FetchContent_Declare(
  CMakeModules
  GIT_REPOSITORY "https://github.com/ZIMO-Elektronik/CMakeModules.git"
  GIT_TAG v0.9.1
  SOURCE_DIR ${CMAKE_BINARY_DIR}/CMakeModules)
FetchContent_MakeAvailable(CMakeModules)

version_from_git()
project(
  Salsa20
  VERSION ${VERSION_FROM_GIT}
  LANGUAGES C CXX)

add_library(Salsa20 STATIC src/salsa20.c)
add_library(Salsa20::Salsa20 ALIAS Salsa20)

if(PROJECT_IS_TOP_LEVEL)
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

if(PROJECT_IS_TOP_LEVEL)
  include(CTest)
endif()

if(BUILD_TESTING AND CMAKE_SYSTEM_NAME STREQUAL CMAKE_HOST_SYSTEM_NAME)
  add_subdirectory(tests)
endif()
