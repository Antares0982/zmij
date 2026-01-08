// A basic print for C++20

#ifndef ZMIJ_PRINT_H_
#define ZMIJ_PRINT_H_

#include <stdio.h>  // fputs

#include <format>  // std::format

template <typename... T> void print(std::format_string<T...> fmt, T&&... args) {
  fputs(std::format(fmt, std::forward<T>(args)...).c_str(), stdout);
}

template <typename... T>
void print(FILE* f, std::format_string<T...> fmt, T&&... args) {
  fputs(std::format(fmt, std::forward<T>(args)...).c_str(), f);
}

#endif  // ZMIJ_PRINT_H_
