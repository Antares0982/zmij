# Żmij

A double-to-string conversion algorithm based on Schubfach

Improvements:
* Faster logarithm approximations
* Fewer branches
* Faster division and modulo
* More efficient digit generation

More than 2x faster than Ryu and 50% faster than [Shubfach](https://github.com/vitaut/schubfach)
on dtoa-benchmark.

| Function       | Time (ns) | Speedup  |
|----------------|----------:|---------:|
| ostringstream  | 875.978   | 0.04x    |
| sprintf        | 746.631   | 0.05x    |
| doubleconv     | 89.011    | 0.42x    |
| to_chars       | 43.916    | 0.85x    |
| ryu            | 37.249    | 1.00x    |
| schubfach      | 24.822    | 1.50x    |
| fmt            | 22.302    | 1.67x    |
| zmij           | 16.648    | 2.24x    |
| dragonbox      | 13.843    | 2.69x    |
| null           | 0.931     | 40.03x   |

<img width="768" height="337" alt="image" src="https://github.com/user-attachments/assets/ac2aed96-451e-450a-a39f-9327504f0efa" />
