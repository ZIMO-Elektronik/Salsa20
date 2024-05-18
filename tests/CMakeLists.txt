include(GoogleTest)

file(GLOB_RECURSE SRC *.c *.cpp)
add_executable(Salsa20Tests ${SRC})

sanitize(address,undefined)

target_common_warnings(Salsa20Tests PRIVATE)

cpmaddpackage(
  NAME
  googletest
  GITHUB_REPOSITORY
  "google/googletest"
  GIT_TAG
  main
  SYSTEM
  YES
  OPTIONS
  "INSTALL_GTEST OFF")

find_package(OpenSSL REQUIRED)
target_link_libraries(
  Salsa20Tests PRIVATE Salsa20::Salsa20 OpenSSL::Crypto OpenSSL::SSL
                       GTest::gtest GTest::gmock)

gtest_discover_tests(Salsa20Tests)
