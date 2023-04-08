#ifndef LIMA_CPU_LIB_H_
#define LIMA_CPU_LIB_H_

#include <cinttypes>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

const extern uint64_t BASE_BITS;

std::vector<uint64_t> convert(boost::multiprecision::cpp_int value, int bitwidth = 64);

// TODO: multiply

void multiply(std::vector<uint64_t> &operand, std::vector<uint64_t> &result);

// TODO: modulo

void module(std::vector<uint64_t> &operand, std::vector<uint64_t> &result, std::vector<std::vector<uint64_t> > multipliers);

// TODO: calculate vector.

std::vector<std::vector<uint64_t> > calculate_multipliers(boost::multiprecision::cpp_int value);

// TODO: loop

#endif // LIMA_CPU_LIB_H_

