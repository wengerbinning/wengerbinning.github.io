## 导入模块


## 预处理宏

模块控制宏

* _STDIO_H
* __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION
* __USE_MISC

* _IOFBF
* _IOLBF
* _IONBF
* BUFSIZ
* EOF

* SEEK_SET
* SEEK_CUR
* SEEK_END
* SEEK_DATA
* SEEK_HOLE

* BUFSIZ
* FILENAME_MAX
* FOPEN_MAX
* TMP_MAX


* RENAME_NOREPLACE
* RENAME_EXCHANGE
* RENAME_WHITEOUT

## 数据类型

* off_t
* off64_t
* ssize_t
* fpos_t


## 数据对象

* FILE * - stdin
* FILE * - stdout
* FILE * - stderr




## 函数接口

* fopen
* freopen
* fopen64
* freopen64
* fdopen
* fopencookie
* fmemopen
* open_memstream
* open_wmemstream


* fclose

* remove
* rename

* setbuf
* setvbuf
* setbuffer
* setlinebuf

* fflush
* fflush_unlocked

* fseek
* fseeko
* fseeko64
* ftell
* ftello
* ftello64
* rewind
* fgetpos
* fgetpos64
* fsetpos
* fsetpos64
* fcloseall
* clearerr
* clearerr_unlocked
* feof
* feof_unlocked
* ferror
* ferror_unlocked

* printf
* fprintf
* sprintf
* snprintf
* vprintf
* vfprintf
* vsprintf
* vsnprintf
* fgetc
* fgetc_unlocked
* getc
* getc_unlocked
* getchar
* getchar_unlocked
* getw
* fgets
* fgets_unlocked
* ungetc
* gets
* getline
* fread
* fread_unlocked

* scanf
* fscanf
* sscanf
* vscanf
* vfscanf
* vsscanf
* fputc
* fputc_unlocked
* putc
* putc_unlocked
* putchar
* putchar_unlocked
* putw
* fputs
* fputs_unlocked
* puts
* fwrite
* fwrite_unlocked


* perror

* tmpnam
* tmpnam_r

* tmpfile
* tmpfile64

* renameat
* renameat2

* popen
* pclose
* ctermid
* cuserid

* flockfile
* ftrylockfile
* funlockfile
