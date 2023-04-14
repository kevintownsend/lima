#include "lima_cpu_lib.h"

#include <iostream>
#include <cinttypes>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

const extern uint64_t BASE_BITS = 26;
const uint64_t BASE_MASK = -1ULL >> (64 - BASE_BITS);

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

std::vector<uint64_t> pad(std::vector<uint64_t> value, int padding) {
  while(value.size() < padding) {
    value.push_back(0);
  }
  return value;
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
  for(int i = 0; i < operand_size; i++) {
    result[2*i] += operand[i] * operand[i];
    for(int j = i + 1; j < operand_size; j++) {
      result[i+j] += 2 * operand[i] * operand[j];
    }
  }

  uint64_t carry = 0;
  for(int i = 0; i < result.size(); i++) {
    result[i] += carry;
    carry = result[i] >> BASE_BITS;
    result[i] &= BASE_MASK;
  }

  // TODO: complete.
}

std::vector<std::vector<uint64_t> > calculate_multipliers(boost::multiprecision::cpp_int value, int N){
  std::vector<std::vector<uint64_t> > ret;

  boost::multiprecision::cpp_int power = 1;
  power <<= N*BASE_BITS;
  for(int i = 0; i < N + 2; i++) {
    boost::multiprecision::cpp_int multiplier = power % value;
    ret.push_back(pad(convert(multiplier, BASE_BITS), N+2));
    power <<= BASE_BITS;
  }

  return ret;
}

std::vector<std::vector<uint64_t> > calculate_multipliers(boost::multiprecision::cpp_int value){
  boost::multiprecision::cpp_int power = 1;
  int i = 0;
  while(power < value) {
    power <<= BASE_BITS;
    i++;
  }
  // TODO: assert N == i;

  return calculate_multipliers(value, i);
}

void modulo(std::vector<uint64_t> &operand, std::vector<uint64_t> &result, std::vector<std::vector<uint64_t> > &multipliers, int N){
  // TODO: from 2N+1 to N (N+1)
  // multiply result value by multiplier
  // add values to result.
  //for(int i = 2*N+1; i > N; i--) {
  for(int i = 0; i < N+2; i++) {
    // TODO: clear result.
    uint64_t old_result = result[2 * N + 2 - i];
    result[2 * N + 2 - i] = 0;
    for(int j = 0; j < N; j++) {
      uint64_t product = old_result * multipliers[N + 2 - i][j];
      result[j+1] += product >> BASE_BITS;
      result[j] += product & BASE_MASK;
    }
  }
  // TODO: normalize.
  // TODO: assert small N+1 value.
}
