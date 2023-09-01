

## 模块依赖

* features.h
* stddef.h
* bits/time.h
* bits/types/clock_t.h
* bits/types/time_t.h
* bits/types/struct_tm.h
* bits/types/struct_timespec.h

* bits/types/clockid_t.h
* bits/types/timer_t.h
* bits/types/struct_itimerspec.h
* bits/types/locale_t.h


## 数据对象


#### __tzname

```c
extern char *__tzname[2];	/* Current timezone names.  */
```

#### __daylight

```c
extern int __daylight;		/* If daylight-saving time is ever in use.  */
```

#### __timezone

```c
extern long int __timezone;	/* Seconds west of UTC.  */
```



## 函数接口

<!-- ISO 11 -->

#### clock

```c
extern clock_t clock (void) __THROW;
```

#### time

```c
extern time_t time (time_t *__timer) __THROW;
```

#### difftime

```c
extern double difftime (time_t __time1, time_t __time0) __THROW __attribute__ ((__const__));
```

#### mktime

```c
extern time_t mktime (struct tm *__tp) __THROW;
```

#### strftime

```c
extern size_t strftime (char *__restrict __s, size_t __maxsize,
			const char *__restrict __format,
			const struct tm *__restrict __tp) __THROW;
```

#### strptime

```c
extern char *strptime (const char *__restrict __s,
		       const char *__restrict __fmt, struct tm *__tp)
     __THROW;
```

#### strptime_l

```c
extern char *strptime_l (const char *__restrict __s,
			 const char *__restrict __fmt, struct tm *__tp,
			 locale_t __loc) __THROW;
```

#### gmtime

```c
extern struct tm *gmtime (const time_t *__timer) __THROW;
```

#### localtime

```c
extern struct tm *localtime (const time_t *__timer) __THROW;
```

#### gmtime_r

```c
extern struct tm *gmtime_r (const time_t *__restrict __timer,
			    struct tm *__restrict __tp) __THROW;
```

#### localtime_r

```c
extern struct tm *localtime_r (const time_t *__restrict __timer,
			       struct tm *__restrict __tp) __THROW;
```

#### asctime

```c
extern char *asctime (const struct tm *__tp) __THROW;
```
#### ctime

```c
extern char *ctime (const time_t *__timer) __THROW;
```

#### asctime_r

```c
extern char *asctime_r (const struct tm *__restrict __tp,
			char *__restrict __buf) __THROW;
```

#### ctime_r

```c
extern char *ctime_r (const time_t *__restrict __timer,
		      char *__restrict __buf) __THROW;
```

#### tzset

```c
extern void tzset (void) __THROW;
```

#### timelocal

```c
extern time_t timelocal (struct tm *__tp) __THROW;
```

#### dysize

```c
extern int dysize (int __year) __THROW  __attribute__ ((__const__));
```

<!--  -->

#### nanosleep

```c
extern int nanosleep (const struct timespec *__requested_time, struct timespec *__remaining);
```

#### clock_getres

```c
extern int clock_getres (clockid_t __clock_id, struct timespec *__res) __THROW;
```

#### clock_gettime

```c
extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp) __THROW __nonnull((2));
```

#### clock_settime

```c
extern int clock_settime (clockid_t __clock_id, const struct timespec *__tp) __THROW __nonnull((2));
```


#### clock_nanosleep

```c
extern int clock_nanosleep (clockid_t __clock_id, int __flags,
			    const struct timespec *__req,
			    struct timespec *__rem);
```

#### clock_getcpuclockid

```c
extern int clock_getcpuclockid (pid_t __pid, clockid_t *__clock_id) __THROW;
```

#### timer_create

```c
extern int timer_create (clockid_t __clock_id,
			 struct sigevent *__restrict __evp,
			 timer_t *__restrict __timerid) __THROW;
```

#### timer_delete

```c
extern int timer_delete (timer_t __timerid) __THROW;
```

#### timer_settime

```c
extern int timer_settime (timer_t __timerid, int __flags,
			  const struct itimerspec *__restrict __value,
			  struct itimerspec *__restrict __ovalue) __THROW;
```

#### timer_gettime

```c
/* Get current value of timer TIMERID and store it in VALUE.  */
extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
     __THROW;
```

#### timer_getoverrun

```c
extern int timer_getoverrun (timer_t __timerid) __THROW;
```

#### timespec_get

```c
extern int timespec_get (struct timespec *__ts, int __base)
     __THROW __nonnull ((1));
```

#### timespec_getres

```c
extern int timespec_getres (struct timespec *__ts, int __base)
     __THROW;
```

#### getdate

```c
extern struct tm *getdate (const char *__string);
```

#### getdate_r

```c
extern int getdate_r (const char *__restrict __string,
		      struct tm *__restrict __resbufp);
```