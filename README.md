# Salsa20

[![build](https://github.com/ZIMO-Elektronik/Salsa20/actions/workflows/build.yml/badge.svg)](https://github.com/ZIMO-Elektronik/Salsa20/actions/workflows/build.yml) [![tests](https://github.com/ZIMO-Elektronik/Salsa20/actions/workflows/tests.yml/badge.svg)](https://github.com/ZIMO-Elektronik/Salsa20/actions/workflows/tests.yml)

<img src="data/images/logo.png" width="10%" align="right">

Original implementation of the [Salsa20](https://en.wikipedia.org/wiki/Salsa20) stream cipher.

```c
#include <salsa20/ecrypt-sync.h>

void encrypt_decrypt_example {
  char const* master_key{"cw4i14l79RPdQOJejv5xVMJPQ1UVnCHw"};
  uint8_t k[32u];
  memcpy(k, master_key, 32u);
  uint8_t v[8u];

  uint8_t plain_data[128u];
  for (auto i{0u}; i < 128u; ++i)
    plain_data[i] = i;

  ECRYPT_ctx x;
  ECRYPT_keysetup(&x, k, 256, 64);
  ECRYPT_ivsetup(&x, v);
  uint8_t cipher_data[128u];
  ECRYPT_encrypt_bytes(&x, plain_data, cipher_data, 128u);

  ECRYPT_ivsetup(&x, v);
  uint8_t return_data[128u];
  ECRYPT_decrypt_bytes(&x, cipher_data, return_data, 128u);
}
```