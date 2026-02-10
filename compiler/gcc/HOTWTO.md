


*

```shell
echo | x86_64-unknown-linux-gnu-gcc -E -v -
echo | gcc -E -v -
```


```shell
x86_64-unknown-linux-gnu-ld --verbose | grep SEARCH_DIR | tr -s ';' '\n'
ld --verbose | grep SEARCH_DIR | tr -s ';' '\n'
```

Using built-in specs.
COLLECT_GCC=x86_64-unknown-linux-gcc
Target: x86_64-unknown-linux
Configured with: /mnt/work/gnu/gcc/configure --prefix=/ --target=x86_64-unknown-linux --enable-languages=c,c++ --disable-multilib --disable-threads : (reconfigured) /mnt/work/gnu/gcc/configure --prefix=/ --target=x86_64-unknown-linux --enable-languages=c,c++ --disable-multilib --disable-threads -with-build-sysroot=/mnt/work/toolchains/toolchain-x86_64-unknown-linux : (reconfigured) /mnt/work/gnu/gcc/configure --prefix=/ --target=x86_64-unknown-linux --enable-languages=c,c++ --disable-multilib --disable-threads --with-build-sysroot=/mnt/work/toolchains/toolchain-x86_64-unknown-linux : (reconfigured) /mnt/work/gnu/gcc/configure --prefix=/ --target=x86_64-unknown-linux --enable-languages=c,c++ --disable-multilib --disable-threads

Thread model: single

Supported LTO compression algorithms: zlib zstd

gcc version 10.5.0 (GCC)

COLLECT_GCC_OPTIONS='-E' '-v' '-mtune=generic' '-march=x86-64'

/mnt/work/toolchains/toolchain-x86_64-unknown-linux/bin/../libexec/gcc/x86_64-unknown-linux/10.5.0/cc1 -E -quiet -v -iprefix /mnt/work/toolchains/toolchain-x86_64-unknown-linux/bin/../lib/gcc/x86_64-unknown-linux/10.5.0/ - -mtune=generic -march=x86-64

ignoring nonexistent directory "/mnt/work/toolchains/toolchain-x86_64-unknown-linux/bin/../lib/gcc/x86_64-unknown-linux/10.5.0/../../../../x86_64-unknown-linux/sys-include"
ignoring nonexistent directory "/mnt/work/toolchains/toolchain-x86_64-unknown-linux/bin/../lib/gcc/x86_64-unknown-linux/10.5.0/../../../../x86_64-unknown-linux/include"


ignoring duplicate directory "/mnt/work/toolchains/toolchain-x86_64-unknown-linux/bin/../lib/gcc/../../lib/gcc/x86_64-unknown-linux/10.5.0/include"
ignoring duplicate directory "/mnt/work/toolchains/toolchain-x86_64-unknown-linux/bin/../lib/gcc/../../lib/gcc/x86_64-unknown-linux/10.5.0/include-fixed"

ignoring nonexistent directory "/mnt/work/toolchains/toolchain-x86_64-unknown-linux/bin/../lib/gcc/../../lib/gcc/x86_64-unknown-linux/10.5.0/../../../../x86_64-unknown-linux/sys-include"
ignoring nonexistent directory "/mnt/work/toolchains/toolchain-x86_64-unknown-linux/bin/../lib/gcc/../../lib/gcc/x86_64-unknown-linux/10.5.0/../../../../x86_64-unknown-linux/include"

#include "..." search starts here:
#include <...> search starts here:
 /mnt/work/toolchains/toolchain-x86_64-unknown-linux/bin/../lib/gcc/x86_64-unknown-linux/10.5.0/include
 /mnt/work/toolchains/toolchain-x86_64-unknown-linux/bin/../lib/gcc/x86_64-unknown-linux/10.5.0/include-fixed
End of search list.





Using built-in specs.

COLLECT_GCC=gcc

Target: x86_64-pc-linux-gnu

Configured with: /build/gcc/src/gcc/configure
--enable-languages=ada,c,c++,d,fortran,go,lto,m2,objc,obj-c++
--enable-bootstrap
--prefix=/usr
--libdir=/usr/lib
--libexecdir=/usr/lib
--mandir=/usr/share/man
--infodir=/usr/share/info
--with-bugurl=https://bugs.archlinux.org/
--with-build-config=bootstrap-lto
--with-linker-hash-style=gnu
--with-system-zlib
--enable-__cxa_atexit
--enable-cet=auto --enable-checking=release --enable-clocale=gnu --enable-default-pie --enable-default-ssp --enable-gnu-indirect-function --enable-gnu-unique-object --enable-libstdcxx-backtrace --enable-link-serialization=1 --enable-linker-build-id --enable-lto --enable-multilib --enable-plugin --enable-shared --enable-threads=posix --disable-libssp --disable-libstdcxx-pch --disable-werror

Thread model: posix

Supported LTO compression algorithms: zlib zstd

gcc version 13.2.1 20230801 (GCC)

COLLECT_GCC_OPTIONS='-E' '-v' '-mtune=generic' '-march=x86-64'

 /usr/lib/gcc/x86_64-pc-linux-gnu/13.2.1/cc1 -E -quiet -v - -mtune=generic -march=x86-64 -dumpbase -

ignoring nonexistent directory "/usr/lib/gcc/x86_64-pc-linux-gnu/13.2.1/../../../../x86_64-pc-linux-gnu/include"

#include "..." search starts here:
#include <...> search starts here:

 /usr/lib/gcc/x86_64-pc-linux-gnu/13.2.1/include
 /usr/local/include
 /usr/lib/gcc/x86_64-pc-linux-gnu/13.2.1/include-fixed
 /usr/include
End of search list.




install: /mnt/work/toolchains/toolchain-x86_64-unknown-linux-gnu/bin/../lib/gcc/x86_64-unknown-linux-gnu/10.5.0/

programs: =/mnt/work/toolchains/toolchain-x86_64-unknown-linux-gnu/bin/../libexec/gcc/x86_64-unknown-linux-gnu/10.5.0/:
/mnt/work/toolchains/toolchain-x86_64-unknown-linux-gnu/bin/../libexec/gcc/:
/mnt/work/toolchains/toolchain-x86_64-unknown-linux-gnu/bin/../lib/gcc/x86_64-unknown-linux-gnu/10.5.0/../../../../x86_64-unknown-linux-gnu/bin/x86_64-unknown-linux-gnu/10.5.0/:
/mnt/work/toolchains/toolchain-x86_64-unknown-linux-gnu/bin/../lib/gcc/x86_64-unknown-linux-gnu/10.5.0/../../../../x86_64-unknown-linux-gnu/bin/

libraries: =
/mnt/work/toolchains/toolchain-x86_64-unknown-linux-gnu/bin/../lib/gcc/x86_64-unknown-linux-gnu/10.5.0/:
/mnt/work/toolchains/toolchain-x86_64-unknown-linux-gnu/bin/../lib/gcc/:

/mnt/work/toolchains/toolchain-x86_64-unknown-linux-gnu/bin/../lib/gcc/x86_64-unknown-linux-gnu/10.5.0/../../../../x86_64-unknown-linux-gnu/lib/x86_64-unknown-linux-gnu/10.5.0/:
/mnt/work/toolchains/toolchain-x86_64-unknown-linux-gnu/bin/../lib/gcc/x86_64-unknown-linux-gnu/10.5.0/../../../../x86_64-unknown-linux-gnu/lib/../lib64/:
/mnt/work/toolchains/toolchain-x86_64-unknown-linux-gnu/bin/../lib/x86_64-unknown-linux-gnu/10.5.0/:

/mnt/work/toolchains/toolchain-x86_64-unknown-linux-gnu/bin/../lib/../lib64/:
/mnt/work/toolchains/toolchain-x86_64-unknown-linux-gnu/bin/../usr/lib/x86_64-unknown-linux-gnu/10.5.0/:
/mnt/work/toolchains/toolchain-x86_64-unknown-linux-gnu/bin/../usr/lib/../lib64/:

/mnt/work/toolchains/toolchain-x86_64-unknown-linux-gnu/bin/../lib/gcc/x86_64-unknown-linux-gnu/10.5.0/../../../../x86_64-unknown-linux-gnu/lib/:

/mnt/work/toolchains/toolchain-x86_64-unknown-linux-gnu/bin/../lib/:
/mnt/work/toolchains/toolchain-x86_64-unknown-linux-gnu/bin/../usr/lib/
