include(GoogleTest)

file(GLOB_RECURSE SRC *.c *.cpp)
add_executable(Salsa20Tests ${SRC})

sanatize("address,undefined")

target_common_warnings(Salsa20Tests PRIVATE)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG main
  GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(googletest)

find_package(OpenSSL REQUIRED)
target_link_libraries(
  Salsa20Tests PRIVATE Salsa20::Salsa20 OpenSSL::Crypto OpenSSL::SSL
                       GTest::gtest GTest::gmock)

gtest_discover_tests(Salsa20Tests)
