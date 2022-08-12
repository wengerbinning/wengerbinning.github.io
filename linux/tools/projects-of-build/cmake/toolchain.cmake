# Target platfrom  
# list(APPEND TARGET_PLATFROMS x64_64 aarch64)

# list(APPEND TOOLCHAINS ${COMMON_LANGUAGE_RUNTIME})

# Default target platfrom is local platfrom.
# exec_program(uname ${HOME} ARGS -m OUTPUT_VARIABLE DEFAULT_TARGET_PLATFROM)

# set(CMAKE_SYSTEM_NAME Linux)

# set(CMAKE_SYSTEM_PROCESSOR aarch64)

# set(TOOLCHAIN "/home/wbzheng/toolchain/aarch64_cortex-a53_gcc_v8.4.0")

# set(CROSS "aarch64-openwrt-linux-musl-")

# set(CMAKE_C_COMPILER "${TOOLCHAIN}/bin/${CROSS}gcc")

# set(CMAKE_CXX_COMPILER "${TOOLCHAIN}/bin/${CROSS}g++")

# set(CMAKE_FIND_ROOT_PATH "${TOOLCHAIN}")

# set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)

# set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)