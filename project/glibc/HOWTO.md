--prefix=$TARGET_PREFIX

--build=$BUILD
--host=$TARGET
--target=$TARGET
--with-binutils=$PREFIX/bin


--cache-file=config.cache

```config.cache
libc_cv_forced_unwind=yes
libc_cv_c_cleanup=yes
libc_cv_arm_tls=yes
```


--enable-add-ons --disable-profile

```shell
#!/usr/bin/env bash

TOOLCHAIN_DIR=

BUILD_DIR="build"
SOURCE_DIR=$(pwd)


#
test -d $BUILD_DIR && rm -rf $BUILD_DIR
mkdir -p $BUILD_DIR

#
cd $BUILD_DIR && {
    #
    $SOURCE_DIR/configure --prefix=/ \
    --target=$TARGET \
    --enable-shared \
    --enable-languages=c,c++

    #
    cd - >/dev/null
}
```