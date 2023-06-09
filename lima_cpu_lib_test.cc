#include "gtest/gtest.h"
#include "lima_cpu_lib.h"

#include <vector>
#include <cinttypes>

namespace {

TEST(CONVERT, SIMPLE) {
  EXPECT_EQ(convert(42), std::vector<uint64_t>({42ULL}));
}

TEST(CONVERT, TWO_VALUE_VECTOR) {
  EXPECT_EQ(convert(0xdeadbeefULL, 8),
      std::vector<uint64_t>({0xefULL, 0xbeULL, 0xadULL, 0xdeULL}));
}

TEST(MULTIPLY, SINGLE_VALUE) {
  std::vector<uint64_t> result({0});
  std::vector<uint64_t> operand({2});
  multiply(operand, result);
  EXPECT_EQ(result, std::vector<uint64_t>({4}));
}

TEST(MULTIPLY, MULTI_VALUE) {
  std::vector<uint64_t> result({0, 0, 0});
  std::vector<uint64_t> operand({2,3});
  multiply(operand, result);
  EXPECT_EQ(result, std::vector<uint64_t>({4, 12, 9}));
}

TEST(MODULE, SINGLE_VALUE) {
  auto multipliers = calculate_multipliers(42);
  std::vector<uint64_t> result({1, 2, 3, 4});
  //modulo(result, result, multipliers, 1);
}

TEST(CALCULATE_MULTIPLIERS, SMALL) {
  //boost::multiprecision::cpp_int();
  auto result = calculate_multipliers(42);
  EXPECT_EQ(result[0], std::vector<uint64_t>({4, 0, 0}));

}
}
