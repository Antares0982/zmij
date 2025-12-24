#include <stdio.h>

#include "zmij.h"

int main() {
  char buf[zmij::double_buffer_size];
  zmij::to_string(6.62607015e-34, buf);
  puts(buf);
}
