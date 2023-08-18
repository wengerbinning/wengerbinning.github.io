stdio.h中定义了三种类型，宏、以及函数。来实现数据的输入与输出。以下函数原型均来自glibc-2.34。

定义的数据类型有size_t、FILE、fpos_t。

* `va_list`
* `off_t`
* `ssize_t`是一个long类型的扩展。
* size_t是一个unsigned int。
* FILE是一个存储文件流类型的对象类型。
* `fpos_t`是一个适合存储文件中任何位置的对象类型。

  ```c
  typedef struct _G_fpos_t fpos_t;
  
  struct _G_fpos_t {
      __off_t __pos;
      __mbstate_t __state;
  };
  ```



定义了一下宏：

* `NULL`是一个空指针常量。
* `_IOFBF`、`_IOLBF`、`_IONBF`是整数常量，适用于setvbuf函数的第三个参数。
* `BUFSIZ`是一个整数常量，代表setbuf的函数使用的缓存区大小。
* `EOF`是代表文件结束。
* `FOPEN_MAX`

还具有一下全局变量

* `FILE *stdin`
* `FILE *stdout`
* `FILE *stderr`

定义以下下函数


* `FILE* fopen(const char *filename, const char *mode);`

  根据指定的模式打开文件，返回一个FILE指针。filename是一个文件的路径，mode是指打开文件的方式有r、w、a、r+、w+、a+。

  ```c
  // function declaration.
  extern FILE *fopen 
      (const char *__restrict __filename, const char *__restrict __modes) 
      __attribute_malloc__ __attr_dealloc_fclose __wur;
  
  libc_hidden_def (__libc_open)
  weak_alias (__libc_open, __open)
  libc_hidden_weak (__open)
  weak_alias (__libc_open, open)
  
  // 
  int __libc_open (const char *file, int oflag)
  {
        int mode;
  
        if (file == NULL)
        {
                __set_errno (EINVAL);
                return -1;
        }
  
        if (__OPEN_NEEDS_MODE (oflag))
        {
                va_list arg;
                va_start(arg, oflag);
                mode = va_arg(arg, int);
                va_end(arg);
        }
  
        __set_errno (ENOSYS);
        return -1;
  }
  ```
  
* `int fclose(FILE *stream);`

  关闭一个文件流对象。

  ```c
  // function declaration.
  extern int fclose (FILE *__stream);
  
  //
  int __close (int fd)
  {
      if (fd < 0)
      {
          __set_errno (EBADF);
          return -1;  
      }

      __set_errno (ENOSYS);
      return -1;
  }
  ```

以下操作是一些格式化的输入与输出的函数。

* `int fprintf(FILE *stream, const char *format, ...);`

  格式化输出内容到文件流中。

  ```c
  // function decalation.
  extern int fprintf (FILE *__restrict __stream, const char *__restrict __format, ...);
  
  //
  ldbl_hidden_def (__fprintf, fprintf)
  ldbl_strong_alias (__fprintf, fprintf)
  
  //
  int __fprintf (FILE *stream, const char *format, ...)
  {
      va_list arg;
      int done;
  
      va_start (arg, format);
      done = __vfprintf_internal (stream, format, arg, 0);
      va_end (arg);
  
      return done;
  }
  ```

* `int printf(const char *format, ...);`

  格式化输出内容到标准输出。
  
  ```c
  // function declaration.
  extern int printf (const char *__restrict __format, ...);
  
  //
  ldbl_strong_alias (__printf, printf);
  ldbl_strong_alias (__printf, _IO_printf);

  //
  int __printf (const char *format, ...)
  {
      va_list arg;
      int done;
  
      va_start (arg, format);
      done = __vfprintf_internal (stdout, format, arg, 0);
      va_end (arg);
  
      return done;
  }
  ```

* `int sprintf(char *str, const char *format, ...);`

  格式化输出内容到字符变量中。

  ```c
  // function decalation.
  extern int sprintf (char *__restrict __s, const char *__restrict __format, ...) __THROWNL;
  
  //
  ldbl_hidden_def (__sprintf, sprintf)
  ldbl_strong_alias (__sprintf, sprintf)
  ldbl_strong_alias (__sprintf, _IO_sprintf)
  
  // 
  int __sprintf (char *s, const char *format, ...)
  {
      va_list arg;
      int done;

      va_start (arg, format);
      done = __vsprintf_internal (s, -1, format, arg, 0);
      va_end (arg);

      return done;
  }
  ```

* `int vfprintf(FILE *stream, const char *format, va_list arg);`

* `int vprintf(const char *format, va_list arg);`

* `int vsprintf(char *str, const char *format, va_list arg);`

  
* `size_t fread(void *ptr, size_t size, size_t nmemb, FFLE *stream);`
* `int fgetpos(FILE *stream);`
* `int fflush(FILE *stream);`
* `int feof(FILE *stream);`
* `void clearerr(FILE *stream);`

* `FILE freopen(const char *filename, const char *mode, FILE *stream);`
* `int fseek(FILE *stream, long int offset, int whence);`
* `int fsetpos(FILE *stream, const fpos_t *pos);`
* `long int ftell(FILE *stream);`
* `size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);`

* `int remove(const char *filename);`
* `int rename(const char *old_filename, const char *new_filename);`

* `void rewind(FILE *stream);`
* `void setbuf(FILE *stream, char *buffer);`
* `int setvbuf(FILE *stream, char *buffer, int mode, size_t size);`
* `FILE* tmpfile(void);`
* `char* tmpnam(char *str);`
* `int fscanf(FILE *stream, const char *format, ...);`
* `int scanf(const char *format, ...);`
* `int sscanf(const char *str, const char *format, ...);`
* `int fgetc(FILE *stream);`
* `char* fgets(char *str, int n, FILE *stream);`
* `int fputc(int char, FILE *stream);`
* `int fputs(const char *str, FILE *stream);`
* `int getc(FILE *stream);`
* `int getchar(void);`
* `char* gets(char *str);`
* `int putc(int char, FILE *stream);`
* `int putchar(int char);`
* `int puts(const char *str);`
* `int ungetc(int char, FILE *stream);`
* `void perror(const char *str);`
* `int snprintf(char *str, size_t size, const char *format, ...);`


* pretreatment

```c
#ifndef _STDIO_H

#if !define(__need_FILE)
#define _STDIO_H   1
#define __need_size_t  
#define __need_NULL  
#include <stddef.h>
#define __need___va_list  
#include <stdarg.h>

#ifndef __GNUC_VA_LIST  
#define __gnuc_va_list __ptr_t  
#endif

#include <gnu/types.h>
#endif /* Don't need FILE.  */
#undef __need_FILE

#ifndef __FILE_defined
```