#include "lima_cpu_lib.h"

#include <iostream>
#include <cinttypes>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

const extern uint64_t BASE_BITS = 26;

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

boost::multiprecision::cpp_int to_cpp_int(std::vector<uint64_t> value, int bitwidth) {
  boost::multiprecision::cpp_int ret = 0;
  for(int i = 0; i < value.size(); i++) {
    ret += boost::multiprecision::cpp_int(value[i]) << (i*bitwidth);
  }
  return ret;
}

void multiply(std::vector<uint64_t> &operand, std::vector<uint64_t> &result){
  std::fill(result.begin(), result.end(), 0);
  uint64_t operand_size = operand.size();
  // TODO: complete.
}
