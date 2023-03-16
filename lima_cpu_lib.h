#ifndef LIMA_CPU_LIB_H_
#define LIMA_CPU_LIB_H_

#include <cinttypes>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

std::vector<uint64_t> convert(boost::multiprecision::cpp_int value, int bitwidth = 64);

#endif // LIMA_CPU_LIB_H_

