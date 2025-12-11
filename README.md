# Żmij

A double-to-string conversion algorithm based on Schubfach

## Features

* High performance
* Fast compile time
* Zero dependencies
* Small, clean codebase consisting of one source file and one header

## Usage

```c++
#include "zmij.h"
#include <stdio.h>

int main() {
  char buf[zmij::buffer_size];
  zmij::dtoa(6.62607015e-34, buf);
  puts(buf);
}
```

## Performance

More than 3x faster than Ryu and ~2x faster than [Schubfach](https://github.com/vitaut/schubfach)
on [dtoa-benchmark](https://github.com/fmtlib/dtoa-benchmark).

| Function     | Time (ns) | Speedup  |
|--------------|----------:|---------:|
| ostringstream| 896.099   | 1.00x    |
| sprintf      | 749.617   | 1.20x    |
| doubleconv   | 87.886    | 10.20x   |
| to_chars     | 43.602    | 20.55x   |
| ryu          | 40.061    | 22.37x   |
| schubfach    | 25.196    | 35.57x   |
| fmt          | 23.828    | 37.61x   |
| dragonbox    | 21.992    | 40.75x   |
| zmij         | 12.839    | 69.79x   |
| null         | 0.971     | 923.25x  |

<img width="788" height="347" alt="image" src="https://github.com/user-attachments/assets/0e3de579-09b7-448e-b1de-b247a31c83c4" />

<img width="882" height="666" alt="image" src="https://github.com/user-attachments/assets/7119c447-6cb2-4b04-9e75-33c19dbf75fb" />

Differences from Schubfach:
* Selection from 1-3 candidates instead of 2-4
* Faster logarithm approximations
* Faster division and modulo
* Fewer branches
* More efficient significand and exponent output
