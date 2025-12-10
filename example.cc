#include "zmij.h"
#include <stdio.h>

int main() {
  char buf[zmij::buffer_size];
  zmij::dtoa(-4.9320966617968882e-226, buf);
  puts(buf);
}
