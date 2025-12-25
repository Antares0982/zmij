// A verifier for https://github.com/vitaut/zmij/.
// Copyright (c) 2025 - present, Victor Zverovich
// Distributed under the MIT license (see LICENSE).

#include <stdint.h>  // uint32_t
#include <stdio.h>   // printf
#include <string.h>  // memcpy

#include <thread>
#include <vector>

#include "dragonbox/dragonbox_to_chars.h"
#include "zmij.h"

int main() {
  unsigned concurrency = std::thread::hardware_concurrency();
  constexpr unsigned long long N = std::numeric_limits<uint32_t>::max() + 1ULL;
  uint32_t n = static_cast<uint32_t>(N / concurrency);
  if (static_cast<uint64_t>(n) * concurrency != N) {
    printf("Unsupported concurrency\n");
    return 1;
  }

  std::vector<std::thread> threads(concurrency);
  for (uint32_t i = 0; i < concurrency; ++i) {
    threads[i] = std::thread([i, n] {
      char actual[zmij::float_buffer_size] = {};
      char expected[32] = {};
      double percent = 100.0 / n;
      for (uint32_t j = 0; j < n; ++j) {
        if (j % 50'000'000 == 0)
          printf("Thread %d progress: %.2f%%\n", i, j * percent);

        uint32_t bits = i * n + j;

        float value = 0;
        memcpy(&value, &bits, sizeof(float));

        zmij::write(actual, sizeof(actual), value);
        *jkj::dragonbox::to_chars(value, expected) = '\0';

        if (strcmp(actual, expected) == 0) continue;
        if (strcmp(actual, "0") == 0 && strcmp(expected, "0e0") == 0) continue;
        if (strcmp(actual, "-0") == 0 && strcmp(expected, "-0e0") == 0)
          continue;

        printf("Output mismatch: %s != %s\n", actual, expected);
        return;
      }
      while (i != 0);
    });
  }

  for (int i = 0; i < concurrency; ++i) threads[i].join();
  printf("Tested %llu values\n", N);
}
