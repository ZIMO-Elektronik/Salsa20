#include <gtest/gtest.h>
#include <array>
#include <cstring>

extern "C" {
#include <salsa20/ecrypt-sync.h>
int bigtest();
}

TEST(Salsa20, smalltest) {
  constexpr char const* master_key{"cw4i14l79RPdQOJejv5xVMJPQ1UVnCHw"};
  uint8_t k[32uz];
  std::memcpy(k, master_key, 32uz);
  uint8_t v[8uz];

  uint8_t plain_data[128uz];
  for (auto i{0uz}; i < 128uz; ++i) plain_data[i] = i;

  ECRYPT_ctx x;
  ECRYPT_keysetup(&x, k, 256, 64);
  ECRYPT_ivsetup(&x, v);
  uint8_t cipher_data[128uz];
  ECRYPT_encrypt_bytes(&x, plain_data, cipher_data, 128u);

  ECRYPT_ivsetup(&x, v);
  uint8_t return_data[128uz];
  ECRYPT_decrypt_bytes(&x, cipher_data, return_data, 128u);

  for (auto i{0uz}; i < 128uz; ++i) EXPECT_EQ(plain_data[i], return_data[i]);
}

TEST(Salsa20, bigtest) { EXPECT_EQ(bigtest(), 0); }

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  return RUN_ALL_TESTS();
}