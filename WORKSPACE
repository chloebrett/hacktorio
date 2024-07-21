load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "aspect_gcc_toolchain",
    sha256 = "3341394b1376fb96a87ac3ca01c582f7f18e7dc5e16e8cf40880a31dd7ac0e1e",
    strip_prefix = "gcc-toolchain-0.4.2",
    urls = [
        "https://github.com/aspect-build/gcc-toolchain/archive/refs/tags/0.4.2.tar.gz",
    ],
)

load("@aspect_gcc_toolchain//toolchain:repositories.bzl", "gcc_toolchain_dependencies")

gcc_toolchain_dependencies()

load("@aspect_gcc_toolchain//toolchain:defs.bzl", "gcc_register_toolchain", "ARCHS")

gcc_register_toolchain(
    name = "gcc_toolchain_x86_64",
    target_arch = ARCHS.x86_64,
)

http_archive(
    name = "sfml",
    build_file = "@//external/sfml:BUILD.bazel",
    sha256 = "6af0f14fbd41dc038a00d7709f26fb66bb7ccdfe6187657ef0ef8cba578dcf14",
    strip_prefix = "SFML-2.5.1-macos-clang",
    urls = ["https://www.sfml-dev.org/files/SFML-2.5.1-macOS-clang.tar.gz"],
)
