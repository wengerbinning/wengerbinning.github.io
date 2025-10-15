libpthread

```c
#include <pthread.h>
```

```
-lpthread
```

main thread

```c
// https://man7.org/linux/man-pages/man3/pthread_create.3.html
int pthread_create (pthread_t *restrict thread, const pthread_attr_t *restrict attr, void *(*start_routine)(void *), void *restrict arg);
```

```c
// https://man7.org/linux/man-pages/man3/pthread_join.3.html
int pthread_join (pthread_t thread, void **retval);
```

```c
// https://man7.org/linux/man-pages/man3/pthread_cancel.3.html
int pthread_cancel (pthread_t thread);
```

Sub thread

```c
// https://man7.org/linux/man-pages/man3/pthread_exit.3.html
void pthread_exit (void *retval);
```