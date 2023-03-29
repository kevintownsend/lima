#include "gtest/gtest.h"
#include "lima_cpu_lib.h"

#include <vector>
#include <cinttypes>

// TODO: include test include.
namespace {

TEST(HELLO, WORLD) {
  EXPECT_STRNE("hello", "world");
}

TEST(CONVERT, SIMPLE) {
  EXPECT_EQ(convert(42), std::vector<uint64_t>({42ULL}));
}

TEST(CONVERT, TWO_VALUE_VECTOR) {
  EXPECT_EQ(convert(0xdeadbeefULL, 8),
      std::vector<uint64_t>({0xefULL, 0xbeULL, 0xadULL, 0xdeULL}));
}

}
