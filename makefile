vim:
	vim -p TODO makefile \
		BUILD \
		lima_cpu_lib.cc \
		lima_cpu_lib.h \
		lima_cpu_lib_test.cc \
		lima_cpu.cc

lima:
	bazel build :lima_cpu_lib
