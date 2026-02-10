
## stdio.h

### 导入模块


### 预处理宏

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

### 数据类型

* off_t
* off64_t
* ssize_t
* fpos_t


### 数据对象

* FILE * - stdin
* FILE * - stdout
* FILE * - stderr

### 函数接口

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

## stdlib.h

### 导入模块

### 预处理宏

### 数据类型

* div_t
* ldiv_t
* lldiv_t

* struct random_data
* struct drand48_data

### 数据对象

### 函数接口

* atof
* atoi
* atol
* atoll
* strtod
* strtof
* strtold
* strtof16
* strtof32
* strtof64
* strtof128
* strtof32x
* strtof64x
* strtof128x
* strtol
* strtoul
* strtoq
* strtouq
* strtoll
* strtoull
* strfromd
* strfromf
* strfroml
* strfromf16

* random
* random_r
* srandom
* srandom_r
* initstate
* initstate_r
* setstate
* setstate_r
* rand
* rand_r
* srand
* drand48
* erand48

* malloc
* calloc
* realloc
* free
* reallocarray
* valloc

* posix_memalign
* aligned_alloc
* abort
* atexit
* exit
* quick_exit
* getenv
* putenv
* setenv
* unsetenv
* clearenv
* mkstemp
* mkstemp64
* mkstemps
* mkstemps64
* mkdtemp
* mkostemp

* system
* realpath
* qsort

* abs
* div
* ldiv
* lldiv
* ecvt
* fcvt
* gcvt
* qecvt
* qfcvt
* qgcvt

* mblen
* mbtowc
* wctomb
* mbstowcs
* wcstombs
* rpmatch
* getsubopt
* posix_openpt
* grantpt
* unlockpt
* ptsname
* ptsname_r
* getpt
* getloadavg
* ttyslot

## unistd.h

### 导入模块

### 预处理宏

* STDIN_FILENO
* STDOUT_FILENO
* STDERR_FILENO

* R_OK
* W_OK
* X_OK
* F_OK


### 数据类型

* ssize_t
* gid_t
* uid_t
* off_t
* off64_t
* useconds_t
* pid_t
* intptr_t
* socklen_t

### 数据对象

### 函数接口

* access
* euidaccess
* eaccess
* execveat
* faccessat
* lseek
* lseek64
* close
* closefrom
* read
* write
* pread
* pwrite
* pipe
* pipe2

* alarm
* sleep
* ualarm
* usleep
* pause
* chown
* fchown
* lchown
* fchownat
* chdir
* fchdir
* getcwd
* get_current_dir_name
* getwd
* dup
* dup2
* dup3
* execve
* fexecve
* execv
* execle
* execl
* execvp
* execlp
* execvpe

* nice
* _exit

* sysconf

* getpid
* getppid
* getpgrp
* __getpgid
* getpgid

## string.h

* size_t
* NULL

管理内存相关的接口

* memcmp
* memcpy
* memmove
* memset
* memchr

管理字符串相关的接口

* strcat
* strchr
* strcmp
* strcoll
* strcpy
* strcspn
* strerror
* strlen
* strpbrk
* strrchr
* strstr
* strtok
* strxfrm

* strncat
* strncmp
* strncpy

## stdint.h

## math.h

## glob.h

## fcntl.h

## getopt.h

## ifaddrs.h

## time.h

## malloc.h

* malloc
* calloc
* realloc
* free
* valloc
* memalign
* malloc_usable_size

## LINKS

*  malloc <https://blog.csdn.net/wang13342322203/article/details/80862382>

man-pages

* stdio.h
  1. <https://man7.org/linux/man-pages/man3/stdio.3.html>
  2. <https://man7.org/linux/man-pages/man0/stdio.h.0p.html>
*
* unistd.h <https://man7.org/linux/man-pages/man0/unistd.h.0p.html>
