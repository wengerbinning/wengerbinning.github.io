install是一个复制文件并可以设置文件属性的工具，并且默认属性是755，该工具有四种用法，使用格式如下：

```shell
install OPTION... [-T] SOURCE DEST
```

复制源文件到目的路径，当目的路径不存在时，默认为文件路径，当DEST是一个存在的目录路径时，将源文件复制到目录路径下；
当使用`-T`参数时，会将目的路径当作一个文件路径，而非一个目录路径。

```shell
install OPTION... SOURCE... DIRECTORY
```

复制多个源文件到目的路径下，该目的路径是一个存在目录路径。

```shell
install OPTION... -t DIRECTORY SOURCE...
```

复制多个源文件到目的路径下，该目的路径是一个存在目录路径。但是目录路径由`-t`参数指定。

```shell
install OPTION... -d DIRECTORY...
```

## option

* `-o OWNER, --owner=OWNER`指定文件的所属用户。
* `-g GROUP, --group=GROUP`指定文件的所属用户组。
* `-m MODE, --mode=MODE`指定文件的权限属性，缺省时默认为755。
* `-b, --backup[=CONTROL]`如果目的路径是一个存在的文件路径，则对该文件做一个备份，当指定CONTROL为以下值时，分别会做不同处理。
  该项也可以使用VERSION_CONTROL环境变量来指定

  * `none`: 对存在文件不做备份。
  * `simple`: 仅做备份，不检查备份文件是会否存在。
  * `existing`:对文件做备份，如果备份文件已存在，则增加数字。
  * `numbered`:增加数字尾缀。

* `-C, --compare`在复制前先讲过已存在的目的文件与源文件进行对比，在一些情况下对目的文件不做修改。
* `-d, --directory`将所有路径当做目录路径，如果不存在则创建；不能递归创建目录。
* `-D`与-d类似，但是仅将目的路径当作目录路径，不存在时创建。
* `-p, --preserve-timestamps`将使用源文件的创建与修改时间作为目的文件的时间。
* `-S, --suffix`指定备份文件的后缀。默认是`~`。也可以使用SIMPLE_BACKUP_SUFFIX环境变量来指定。
* `-t DIRECTORY, --target-directory=DIRECTORY`将多个源文件复制到指定的目录下。
* `-T, --no-target-directory`将目的路径当作一个文件路径，而非一个目录路径。
* `--strip-program=PROGRAM`执行strip程序的路径。
* `-s, --strip`对文件进行strip.
* `--preserve-context`保留SELinux的安全上下文。
* `-Z --context[=CTX]`设置目的文件SELinux的安全是安全上下文
* `-v, --verbose`，详细显示过程。
* `--help`显示帮助。
* `--version`显示版本信息。





##

安装$DESTDIR/usr/sbin/下多个可执行文件到$SYSROOT/usr/sbin/下，$SYSROOT/usr/sbin可以不存在。

```shell
install -m 554 -D -t $SYSROOT/usr/sbin $DESTDIR/usr/sbin/*

# stip all file
install -s --strip-program=strip -m 775 -D -t $SYSROOT/usr/sbin $DESTDIR/usr/sbin/*
```

创建安装目录

```shell
install -d $SYSROOT/usr/{bin,sbin,share,include,lib}
```