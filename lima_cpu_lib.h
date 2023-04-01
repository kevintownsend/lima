#ifndef LIMA_CPU_LIB_H_
#define LIMA_CPU_LIB_H_

#include <cinttypes>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

std::vector<uint64_t> convert(boost::multiprecision::cpp_int value, int bitwidth = 64);

// TODO: multiply

void multiply(std::vector<uint64_t> &operand, std::vector<uint64_t> &result);

// TODO: modulo

// TODO: loop

#endif // LIMA_CPU_LIB_H_

