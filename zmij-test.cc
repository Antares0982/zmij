#include "zmij.h"
#include <string>
#include <gtest/gtest.h>

auto dtoa(double value) -> std::string {
  char buffer[zmij::buffer_size];
  zmij::dtoa(value, buffer);
  return buffer;
}

TEST(zmij_test, normal) {
  EXPECT_EQ(dtoa(6.62607015e-34), "6.62607015e-34");
}

TEST(zmij_test, zero) {
  EXPECT_EQ(dtoa(0), "0");
  EXPECT_EQ(dtoa(-0.0), "-0");
}

TEST(zmij_test, inf) {
  EXPECT_EQ(dtoa(std::numeric_limits<double>::infinity()), "inf");
  EXPECT_EQ(dtoa(-std::numeric_limits<double>::infinity()), "-inf");
}

TEST(zmij_test, shorter) {
  // Schubfach would pick a shorter underestimate u'.
  EXPECT_EQ(dtoa(-4.932096661796888e-226), "-4.932096661796888e-226");
}

auto main(int argc, char** argv) -> int {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
