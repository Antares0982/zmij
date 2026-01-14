# 🐉 Żmij

A double-to-string conversion algorithm based on [Schubfach](https://fmt.dev/papers/Schubfach4.pdf)
and [yy](https://github.com/ibireme/c_numconv_benchmark/blob/master/vendor/yy_double/yy_double.c)
with implementations in C and C++

## Features

* Round trip guarantee
* Shortest decimal representation
* Correct rounding
* High [performance](#performance)
* Fast [compile time](#compile-time)
* IEEE 754 `double` and `float` support
* Safer API than classic `dtoa`
* Negative zero dependencies
* Small, clean codebase consisting of one [source file](
  https://github.com/vitaut/zmij/blob/main/zmij.cc) and an optional [header](https://github.com/vitaut/zmij/blob/main/zmij.h)
* Permissive [license](https://github.com/vitaut/zmij/blob/main/LICENSE)

## Usage

```c++
#include "zmij.h"
#include <stdio.h>

int main() {
  char buf[zmij::double_buffer_size];
  zmij::write(buf, sizeof(buf), 5.0507837461e-27);
  puts(buf);
}
```

## Performance

More than 4x faster than [Ryu](https://github.com/ulfjack/ryu) used by multiple
C++ standard library implementations, 9x faster than [double-conversion](
https://github.com/google/double-conversion) and ~2.5x faster than
[Schubfach](https://github.com/vitaut/schubfach)
on [dtoa-benchmark](https://github.com/fmtlib/dtoa-benchmark) run on Apple M1.

| Function            | Time (ns) | Speedup |
|---------------------|----------:|--------:|
| ostringstream       | 888.474   | 0.83x   |
| sprintf             | 734.683   | 1.00x   |
| double-conversion   | 86.827    | 8.46x   |
| to_chars            | 42.795    | 17.17x  |
| ryu                 | 39.258    | 18.71x  |
| schubfach           | 25.199    | 29.15x  |
| fmt                 | 23.718    | 30.98x  |
| dragonbox           | 21.602    | 34.01x  |
| yy                  | 14.960    | 49.11x  |
| xjb64               | 10.598    | 69.32x  |
| zmij                | 9.567     | 76.79x  |
| null                | 0.993     | 739.80x |

<img width="922" height="406" alt="image" src="https://github.com/user-attachments/assets/52402fa4-084b-4002-b125-4655a4db10a2" />

<img width="833" height="669" alt="image" src="https://github.com/user-attachments/assets/dae662e3-a18c-4edf-b3a3-baea4830d348" />

## Compile time

Compile time is ~135ms by default and ~155ms with optimizations enabled as measured by

```
% time c++ -c zmij.cc [-O2]
```

taking the best of 3 runs.

## Languages

* C++: https://github.com/vitaut/zmij/blob/main/zmij.cc (reference implementation)
* C: https://github.com/vitaut/zmij/blob/main/zmij.c
* Rust: https://github.com/dtolnay/zmij
* Zig: https://github.com/de-sh/zmij

## Differences from Schubfach

* 1 instead of 3 multiplications by a power of 10 in the common case
* Faster logarithm approximations
* Faster division and modulo
* Fewer conditional branches
* More efficient significand and exponent output
* Improved storage of powers of 10
* SIMD support

## Name

Żmij (pronounced roughly zhmeey or more precisely /ʐmij/) is a Polish word that refers
to a mythical dragon- or serpent-like creature. This continues the dragon theme [started
by Steele and White](https://fmt.dev/papers/p372-steele.pdf). Nice feature of this name
is that it has a floating point in the first letter.

## Acknowledgements

We would like to express our gratitude to the individuals who have made
**Żmij** possible:

* Victor Zverovich ([@vitaut](https://github.com/vitaut)) - Original author and
  maintainer of Żmij.

* Tobias Schlüter ([@TobiSchluter](https://github.com/TobiSchluter)) -
  Contributed significant performance and portability improvements, including
  SIMD/SSE support and core algorithm refinements that enhance execution speed
  and cross-platform compatibility.

* Dougall Johnson ([@dougallj](https://github.com/dougallj)) – Authored the
  NEON implementation and contributed many optimization ideas, substantially
  improving performance on ARM platforms.

* Alex Guteniev ([@AlexGuteniev](https://github.com/AlexGuteniev)) -
  Contributed multiple fixes and improvements across build systems, platform
  compatibility, and testing infrastructure.

* Xiang JunBo ([@xjb714](https://github.com/xjb714)) - Contributed
  high-performance BCD digit extraction algorithm and additional optimization
  ideas used across scalar and SIMD code paths.

* David Tolnay ([@dtolnay](https://github.com/dtolnay)) - Created and maintains
  the [Rust port of Żmij](https://github.com/dtolnay/zmij), expanding the
  algorithm's reach and adoption in the Rust ecosystem.

* Raffaello Giulietti - Author of the Schubfach algorithm, whose work forms a
  foundational basis for Żmij.

* Yaoyuan Guo ([@ibireme](https://github.com/ibireme)) - Author of the yy
  algorithm, whose ideas influenced key optimizations used in Żmij.

* Cassio Neri ([@cassioneri](https://github.com/cassioneri)) - Proposed the
  single-candidate rounding strategy used in Żmij.

* Junekey Jeon ([@jk-jeon](https://github.com/jk-jeon)) - Author of the
  Dragonbox algorithm, which informed design and benchmarking comparisons for
  Żmij.

* Community contributors who provided feedback, issues, suggestions, and
  occasional commits, helping improve the robustness and performance of Żmij.
