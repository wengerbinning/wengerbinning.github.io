Declaring Attributes of Functions





#### alias

#### aligned 

#### alloc_size

#### always_inline

#### gnu_inline

#### artificial

#### bank_switch

#### flatten

#### error 

#### warning 

#### cdecl

#### const

#### constructor

#### destructor

#### deprecated

#### disinterrupt

#### dllexport

#### dllimport

#### eightbit_data

#### exception_handler

#### externally_visible

#### far

#### fast_interrupt

#### fastcall

#### thiscall

#### format 

#### format_arg 

#### function_vector

#### ifunc 

#### interrupt

#### nonnull 

#### noreturn

#### unused

#### used

#### weak

weak属性将声明符号标记为弱符号而并非一个全局符号。该功能主要用于定义可由用户代码重写呃库函数， 
也可以用于非函数声明。

#### weakref

weakref属性将声明符号标记为弱引用， 如果没有参数， 需要尾随一个alias属性来指定目标符号；
当然目标符号也可以由参数直接给出。这两种情况下， weakref都将隐式的将声明符号标记为弱符号。
如果没有参数或alias属性指定目标符号， weakref就等同于weak。





## LINKS

* <https://gcc.gnu.org/onlinedocs/gcc-4.8.5/gcc/Function-Attributes.html#Function-Attributes>