load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "main",
    srcs = ["main.cpp"],
    hdrs = ["main.hpp"],
    deps = [
        "//external/sfml",
    ],
)

cc_binary(
    name = "hacktorio",
    srcs = ["main.cpp"],
    deps = [
        ":main",
    ],
)
