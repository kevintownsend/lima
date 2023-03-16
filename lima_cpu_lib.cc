#include "lima_cpu_lib.h"

#include <iostream>
#include <cinttypes>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

std::vector<uint64_t> convert(boost::multiprecision::cpp_int value, int bitwidth) {
  uint64_t mask = -1ULL >> (64-bitwidth);
  int i = 0;
  // TODO: figure out precision function.
  // value.precision();
  std::vector<uint64_t> ret;
  while(value) {
    ret.push_back((value & mask).convert_to<uint64_t>());
    value >>= bitwidth;
    i++;
  }
  return ret;
}

// TODO: add a function.

