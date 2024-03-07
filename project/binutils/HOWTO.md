


#### 编译脚本

```shell
#!/usr/bin/env bash

BUILD_DIR="build"
SOURCE_DIR=$(pwd)
DEST_DIR="${BUILD_DIR}/destdir"

#
test -d $BUILD_DIR && rm -rf $BUILD_DIR
mkdir -p $BUILD_DIR

#
cd $BUILD_DIR && {
	#
	# $SOURCE_DIR/configure --prefix=/ --disable-multib
	$SOURCE_DIR/configure --prefix=/ --target=aarch64-unknown-linux-glibc --disable-multib

	#
	make -j4

	#
	make install $DESTDIR=$DEST	_DIR

	#
	cd - >/dev/null
}

```