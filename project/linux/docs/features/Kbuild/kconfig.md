


```c
#define config_enabled(config)      _config_enabled(config)
#define _config_enabled(config)     __config_enabled(__ARG_PLACEHOLDER_##config)
#define __config_enabled(arg1_or_junk)      ___config_enabled(arg1_or_junk 1, 0)
#define ___config_enabled(__ignored, val, ...)      val

#define IS_BUILTION(option) config_enabled(option)
#define IS_MODULE(option)   config_enabled(option##_MODULE)

#define IS_ENABLED(option)  (IS_BUILTION(option) || IS_MODULE(option))
```


## FILES

include/linux/kconfig.h