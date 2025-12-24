// A verifier for https://github.com/vitaut/zmij/.
// Copyright (c) 2025 - present, Victor Zverovich
// Distributed under the MIT license (see LICENSE).

#include <math.h>    // isnan
#include <stdint.h>  // uint32_t
#include <stdio.h>   // printf
#include <string.h>  // memcpy

#include <charconv>

#include "zmij.h"

int main() {
  char actual[zmij::float_buffer_size] = {};
  char expected[32] = {};
  unsigned long long i = 0, n = ~uint32_t();
  double percent = 100.0 / n;
  for (; i <= n; ++i) {
    if (i % 50'000'000 == 0) printf("Progress: %.2f%%\n", i * percent);

    uint32_t bits = i;
    float f = 0;
    memcpy(&f, &bits, sizeof(float));

    zmij::to_string(f, actual);
    *std::to_chars(expected, expected + 32, f, std::chars_format::scientific)
         .ptr = '\0';

    if (strcmp(actual, expected) == 0) continue;
    if (strcmp(actual, "0") == 0 && strcmp(expected, "0e+00") == 0) continue;
    if (strcmp(actual, "-0") == 0 && strcmp(expected, "-0e+00") == 0) continue;
    if (strcmp(actual, "nan") == 0 && strncmp(expected, "nan", 3) == 0)
      continue;
    if (strcmp(actual, "-nan") == 0 && strncmp(expected, "-nan", 4) == 0)
      continue;

    printf("Roundtrip failure: %s != %s\n", actual, expected);
    return 1;
  }
  printf("Tested %lld values\n", i);
}
