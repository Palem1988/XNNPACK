workspace(name = "xnnpack")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Google Test framework, used by most unit-tests.
http_archive(
     name = "com_google_googletest",
     urls = ["https://github.com/google/googletest/archive/master.zip"],
     strip_prefix = "googletest-master",
)

# Google Benchmark library, used in micro-benchmarks.
http_archive(
    name = "com_google_benchmark",
    urls = [
        "https://github.com/google/benchmark/archive/master.zip"
    ],
    strip_prefix = "benchmark-master",
    build_file = "@//third_party:benchmark.BUILD",
)

# FP16 library, used for half-precision conversions
http_archive(
    name = "FP16",
    strip_prefix = "FP16-ba1d31f5eed2eb4a69e4dea3870a68c7c95f998f",
    sha256 = "9764297a339ad73b0717331a2c3e9c42a52105cd04cab62cb160e2b4598d2ea6",
    urls = [
        "https://github.com/Maratyszcza/FP16/archive/ba1d31f5eed2eb4a69e4dea3870a68c7c95f998f.tar.gz",
    ],
    build_file = "@//third_party:FP16.BUILD",
)

# FXdiv library, used for repeated integer division by the same factor
http_archive(
    name = "FXdiv",
    strip_prefix = "FXdiv-f8c5354679ec2597792bc70a9e06eff50c508b9a",
    sha256 = "7d3215bea832fe77091ec5666200b91156df6724da1e348205078346325fc45e",
    urls = [
        "https://github.com/Maratyszcza/FXdiv/archive/f8c5354679ec2597792bc70a9e06eff50c508b9a.tar.gz",
    ],
    build_file = "@//third_party:FXdiv.BUILD",
)

# pthreadpool library, used for parallelization
http_archive(
    name = "pthreadpool",
    strip_prefix = "pthreadpool-0e275fe56094626349c55a524ea8b71a85daa64b",
    sha256 = "c2328fdf9e48ac9b928953bcbc442eb14402d393e4cfae0541581a3d39efca9d",
    urls = [
        "https://github.com/Maratyszcza/pthreadpool/archive/0e275fe56094626349c55a524ea8b71a85daa64b.tar.gz",
    ],
    build_file = "@//third_party:pthreadpool.BUILD",
)

# clog library, used for logging
http_archive(
    name = "clog",
    strip_prefix = "cpuinfo-d5e37adf1406cf899d7d9ec1d317c47506ccb970",
    sha256 = "3f2dc1970f397a0e59db72f9fca6ff144b216895c1d606f6c94a507c1e53a025",
    urls = [
        "https://github.com/pytorch/cpuinfo/archive/d5e37adf1406cf899d7d9ec1d317c47506ccb970.tar.gz",
    ],
    build_file = "@//third_party:clog.BUILD",
)

# cpuinfo library, used for detecting processor characteristics
http_archive(
    name = "cpuinfo",
    strip_prefix = "cpuinfo-d5e37adf1406cf899d7d9ec1d317c47506ccb970",
    sha256 = "3f2dc1970f397a0e59db72f9fca6ff144b216895c1d606f6c94a507c1e53a025",
    urls = [
        "https://github.com/pytorch/cpuinfo/archive/d5e37adf1406cf899d7d9ec1d317c47506ccb970.tar.gz",
    ],
    build_file = "@//third_party:cpuinfo.BUILD",
)

# psimd library, used for fallback 128-bit SIMD micro-kernels
http_archive(
    name = "psimd",
    strip_prefix = "psimd-4f2c53947184b56f58607b9e777416bb63ebbde1",
    sha256 = "7d1795ebf289af26e404cff5877c284775e491414cf41d7d99ab850ceaced458",
    urls = [
        "https://github.com/Maratyszcza/psimd/archive/4f2c53947184b56f58607b9e777416bb63ebbde1.tar.gz",
    ],
    build_file = "@//third_party:psimd.BUILD",
)

# Android NDK location and version is auto-detected from $ANDROID_NDK_HOME environment variable
android_ndk_repository(name = "androidndk")

# Android SDK location and API is auto-detected from $ANDROID_HOME environment variable
android_sdk_repository(name = "androidsdk")
