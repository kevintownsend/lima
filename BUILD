load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "lima_cpu_lib",
    srcs = ["lima_cpu_lib.cc"],
    hdrs = ["lima_cpu_lib.h"],
    deps = ["@boost//:algorithm"],
    visibility = ["//main:__pkg__"],
)

cc_test(
    name = "lima_cpu_lib_test",
    srcs = ["lima_cpu_lib_test.cc"],
    deps = [
        ":lima_cpu_lib",
        "@com_google_googletest//:gtest_main",
        ],
)

cc_binary(
    name = "lima_cpu",
    srcs = ["lima_cpu.cc"],
    deps = [":lima_cpu_lib"],
)
