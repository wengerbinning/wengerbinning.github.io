
Windows是Microsoft开发的一款桌面级操作系统。


磁盘分区、磁盘格式化、磁盘修复、Ghost备份

win7中有command.com（在ntvdm.exe）进程中的程序，是一个16位的DOS应用程序；

Windows Vista++不再支持；在XP中执行`\I386\WINNT32.EXE /cmdcons`安装恢复控制台程序。

修改MAC地址： 计算机`\HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Control\Class\{4d36e972-e325-11ce-bfc1-08002be10318}\0014\Ndi\params\NetworkAddress`

nero
* fdisk
* format
* de
* PQ
* vol：显示卷标；
* label：管理卷标。
* convert：将fat卷转化为NTFS。
* chkdsk：检查磁盘。
* recover:从坏磁盘恢复刻度信息。
* compact：显示或更改NTFS分区上的文件或目录压缩。
* defrag：磁盘碎片整理。
* ghost：系统备份。
* cleanmgr：系统临时文件清理。
* sfc.exe /purgecache:清除文件缓存。

* 文件:`C:/hiberfil.sys`

* 关闭系统休眠: `powercfg -h off`

在Windows 2000之后的操作系统虽然不支持DOS，但是保留了CMD，除了CMD是依赖于Wondows OS之外，
与DOS相同；在CMD之外，又增加了Powershell的支持；powershell兼容cmd，这份笔记是基于cmd管理的。

在运行窗口可以打开常用的应用程序`cmd`、`calc`、`gredit`、msconfig、secpol.msc。

**DLL**

DLL(动态链接库)是指语一组可调用的子例程，被链接到同一个文件中。不可执行的.NET程序集也被编译成
DLL，但是，没有导出成任何子例程， 而是由CLR解析出编译的单元，以便访问对应的数据类型和成员。

**进程**

进程（Process）是一个资源容器，包含虚拟地址空间、已打开的句柄列表、安全环境、进程ID、至少一个执行线程。

**线程**

线程（Thread）是Windows调度的实体，线程包含一组寄存器、两个栈、线程局部存储(TLS)、线程ID

**纤程**

纤程(Fiber)是应用程序可以调度他自己的执行单位，也被称作轻量线程；


**UMS**

用户模式调度(UMS, User Mode Scheduling)的线程仅在64位上可用


**句柄表**


**访问令牌**

访问令牌(Access token)是保存进程的安全环境的对象。

**VAD**

虚拟地址描述符(VAD, Virtual Address Descriptor)

**Job**

作业(job)是将一组进程当作一个整体来管理。

## 发展简述

1983年11月10日，Microsoft宣布开发一个图形用户界面操作系统——Micorsoft Windows。在1985年发布Windows 1.0，只是对MS-DOS的扩展；1987年，发布Windows 2.0；1990年发布Windows 3.0，是第一个在保护模式下运行应用程序的版本

* Windows 1.0：1985年发布。只是对MS-DOS的扩展。
* Windows 2.0：1987年发布。使用了可重叠式窗口，增强了键盘和鼠标接口。
* Windows 3.0：1990年发布。对Intel的286、386、486MCU保护模式的支持。
* Windows NT：1993年发布。可以移植到非Intel处理器上。
* Windows 95：1995年8月发布。集成Windows 3.x与Windows NT。代号Chicago，共有5个版本。
* Windows NT 4.0：1996年7月发布。共有4个版本。
* Windows 98：1998年6月发布。代号Memphis。将internet explore集成到Windows接口与Wenjian管理器中。
* Windows 2000：2000年发布。共有4个版本，Winodws9x系列又发行了Windows me。
* Windows ME：2000年09月发布。
* Windows XP：2001年发布。集成Windows 2000与Windows ME。
* Windows Server 2003：2003年04月发布。共有7种版本。
* Windows Vista：2007年01月发布。引入限制用户模式，支持防火墙。共有6个版本。
* Windows Server 2008：
* Windows 7：2009年10月发布。
* Windows 8：2012年10月发布。
* Windows 10：2015年07月发布。
* Windows Server 2016：2016年09月发布。




## Windows 基础框架

### Windows API

Windows API是针对Windows操作系统家族的用户模式提供的系统编程接口。Win32 API是指32位版本的
Windows操作系统的编程接口，以区分16位版本的Windows操作系统的编程接口，在这里Windows API是指
兼容32位与64位的Windows API。该API在Windows SDK文档中有详细描述。具体包含基本服务、组件服务、
用户界面服务、图形和多媒体服务、消息和协作、网络、Web服务。

### Microsft.NET

Microsoft.NET框架是由框架类库(FCL, Framework Class Library)与公共语言运行库
(CLR, Common Language Runtime)组成，CLR提供以下特性：即时编译、类型检验、垃圾回收、代码安全




## Windows 服务管理

Windows服务是指由Windows服务控制管理启动的进程。

## Windows 系统管理

* 【功能】管理时间日期：

  ```cmd
  @rem 显示及设置日期，需要管理员权限。
  date
  @rem 显示及设置时间，需要管理员权限。
  time
  ```

### Windows 网络管理

* 【命令】`telnet`：使用Telnet协议与远程计算机进行通信,在使用之前,确保服务端服务开启,并且在win7+上需要将登录的用户添加在TelnetClient组中(组添加在组策略中`lusrmgr.msc`)。

  ```cmd
  telnet [ServerIP]     # 连接到服务器,不带参数时进入Telent Client，在Telnet Client中只能使用以下命令。
  ```

  > * `open [ServerIP] [Port]`：连接服务器，可以缩写为o。
  >   * `ServerIP`：指定连接的服务器的地址，如果未指定则使用本地服务器。
  >   * `Port`：指定使用端口。
  > * `close [ServerIP]`：断开服务器连接，可以缩写为c。
  >   * `ServerIP`：指定断开的服务器地址，如果未指定则使用本地服务器。
  > * `quit`：退出Telnet Client，可以缩写为q。
  > * `set`: 设置Telnet Client参数。
  >   * `ServerIP`：指定管理的服务器地址，如果未指定使用本地服务器。
  >   * `ntlm`：打开ntlm身份验证。
  >   * `localecho`：打开本地回显。
  >   * `term {ansi|vt100|vt52|vtnt}`：指定终端类型。
  >   * `escape <Character>`：设置escape字符，在输入组合字符时，按住对应控制键的同时输入即可。
  >   * `logfile <filename>`：设置日志文件，必须是本地计算机。
  >   * `logging`：打开日志记录。
  >   * `bsasdel`：将<kbd>Backspace</kbd>设置为删除键。
  >   * `crlf`：设置新的行模式，在该模式下导致<kbd>Enter</kbd>键发送0X0D、0X0A。
  >   * `delasbs`：将<kbd>Delete</kbd>设置成退格键。
  >   * `mode {console|stream}`：设置操作模式。
  > * `unset`：关闭之前设置，参数同set。
  > * `sent`：发送信息。
  >   * `ServerIP`：指定通信的服务器。
  >   * `ao`：终止输出。
  >   * `ayt`：发送消息。
  >   * `esc`：发送转义字符。
  >   * `ip`：中断进程。
  >   * `synch`：执行Telnet同步操作。

* 【命令】`tftp`：使用TFTP或Daemon的远程计算机（尤其是运行UNIX的计算机）传输文件。

  ```cmd
  tftp <ServerIP> [{get|put}] [source] [destination]    # 使用TFTP传输文件，参数在服务器地址之前。
  ```

  > * `-i`：指定二进制图像传送模式，默认使用ASCII模式传送。
  > * `<ServerIP>`：指定本地计算机或远程计算机。
  > * `{get|put}`：get将从服务器上下载文件，put将上传文件，get下载文件。
  > * `source`：本地文件路径。
  > * `destination`：服务器文件路径。

* 【命令】`ftp`：使用FTP传输文件。

  ```cmd
  ftp <ServerIP>                                        # 登录到ftp服务器,参数必须放在服务器地址之前。
  ```

  > * `-v`：禁止显示ftp服务器的响应。
  > * `-d`：启用调试、显示在ftp客户端和ftp服务器之间传输的所有命令。
  > * `-i`：在传输多个文件时，禁用交互提示。
  > * `-n`：在建立初始连接后禁止自动登录功能。
  > * `-g`：禁用文件名组合，Glob允许使用*与？作为本地文件和路径名的通配字符。
  > * `-s:<FileName>`：指定在启动ftp后自动运行的脚本文件。
  > * `-a`：指定绑定ftp数据连接时可以使用任何本地接口。
  > * `-w:<WindowSize>`：指定传输缓存的大小，默认为4096bit。
  > * `-A`：匿名登录ftp服务器。

* 【命令】`ping`：通过ICMP的请求响应来验证计算机键的IP级连接，用于检测网络连接性、可到达性和名词解析的疑难问题的主要TCP/IP命令。

  ```cmd
  ping          # 显示ping的帮助信息
  ```

  > * `-t`：持续发送请求，直到命令中断。
  > * `-a`：对IP地址进行反向解析。
  > * `-n <Count>`：指定发送请求次数，默认为4次。
  > * `-l <Size>`：指定请求数据的字段长度，默认为32，最大为65527。
  > * `-f`：指定发送的请求带有不要拆分标志，响应不能由目的地路径上的路由器进行拆分，可用于检测并解决PMTU的故障。
  > * `-i <TTL>`：指定发送请求消息的IP标题中的TTL字段值，其默认值是主机的默认值TTL值，对于XP默认值为128，TTL最大值为255.
  > * `-v <TOS>`：指定请求消息IP标题中的TOS字段值，默认值为0，范围在0~255。
  > * `-r <Count>`：指定IP标题中的“记录路由”选项用于记录请求与响应使用的路径，范围1~9。
  > * `-s <Count>`：指定IP标题中的网络时间戳，范围1~4。
  > * `-j <HostList>`：
  > * `-k <HostList>`：
  > * `-w <Timeout>`：指定等待响应的最大时间（ms），默认为4000ms。
  > * `<IPAdress>`： 指定目的端地址。

* 【命令】`ipconfig`：查看网络配置信息，管理网络配置。

  ```cmd
  ipconfig      # 查看网络配置信息
  ```

  > * `/all`：详细显示网络配置信息
  > * `/renew`：更新动态的IP地址，即从DHCP服务器中租用新的地址，一般地址相同。
  > * `/release`：取消DHCP的IP租用。
  > * `/flushdns`：清理并重设DNS客户解析器缓存的内容。
  > * `/displaydns`：显示DNS客户客户解析器缓存的内容。
  > * `/registerdns`：初始化计算机上配置的DNS名称和IP地址的手工动态注册。
  > * `/showclassid <Adapter>`：显示指定适配器DHCP类别的名称。
  > * `/setclassid <Adpater> [<ClassID>]`：配置特定的DHCP类别ID。
  > * `/batch bak-netcfg`：进行网络备份，只能在Windows 98以下使用。

* 【命令】`netsh`：网络配置工具，在Windows XP即以上使用。

  > * `dump`

* 【命令】`getmac`：获取计算机中所有网卡的MAC地址以及每个地址的网络协议列表。

  ```cmd
  getmac        # 获取所有网卡地址
  ```

  > * `/s <Computer>`：指定远程计算机名称或IP地址，默认为本地计算机。
  > * `/u <Domain\User>`：指定执行账户，默认为本地的当前用户。
  > * `/p <Password>`：指定账户密码。
  > * `/fo {TABLE|LIST|CSV}`：指定输出格式，默认为TABLE。
  > * `/nh`：取消列标题显示。
  > * `/v`：指定详细显示信息。

* 【命令】`netstat`：用于显示活动的TCP连接、计算机侦听的端口、以太网统计信息、IP路由表、IP统计信息。

  ```cmd
  netstat       # 显示活动的TCP连接
  ```

  > * `-a`：显示所有活动的TCP连接以及计算机侦听的TCP和UDP端口。
  > * `-e`：显示以太网统计信息。
  > * `-n`：显示活动的TCP连接。
  > * `-o`：显示活动的TCP连接并包括每一个连接的进程PID。
  > * `-p <Protocol>`：显示Protocol所指定的协议的连接，Protocol={TCP|UDP|TCPv6|UDPv6}。
  > * `-r`：显示IP路由表中的内容。
  > * `-s`：按协议显示统计信息。
  > * `<Interval>`：间隔时间，每隔Interval秒重新显示一次选定的信息。

* 【命令】`arp`：用于显示和修改ARP缓存中的项目。

  ```cmd
  arp -a        # 显示所有接口的当前ARP缓存表
  ```

  > * `-a [<IPAdress>]`：显示所有接口的ARP缓存表。
  > * `-g`：与-a参数相同。
  > * `-d <IPAdress>`：删除指定IP地址项。
  > * `-s <IPAdress> <EtherAddr> [<IfaceAddr>]`：向ARP缓存添加可以将IP地址TnetAddr解析为物理地址EtherAddr的静态项，该参数需要管理员权限执行。

* 【命令】`net`：


### Windows 进程管理

* 【命令】`ntsd`：用户态调式工具，终止taskkill无法终止的进程，无法终止System、SMSS.EXE、CSRSS.EXE；

* 【命令】`tasklist`：这是Windows XP中新增的命令，用来显示运行在本地或远程计算机上的所有进程的命令行工具。

  ```cmd
  tasklist          # 显示所有进程的信息
  ```

  > * `/s <Computer>`：指定远程计算机名称或IP地址，默认为本地计算机。
  > * `/u <Domain\User>`：指定执行账户，默认为本地的当前用户。
  > * `/p <Password>`：指定账户密码。
  > * `/fo {TABLE|LIST|CSV}`：指定输出格式，默认为TABLE。
  > * `/nh`：取消列标题显示。
  > * `/fi <FilterName>`：指定查询条件。
  > * `/m [<ModuleName>]`：显示进程的模块信息，未指定时显示所有，不能与/svc或/v参数同时使用。
  > * `/svc`：无间断地列出每个进程的所有服务信息，只在显示格式为TABLE时有效，且不能与/m或/v同时用。
  > * `/v`：配置输出详细任务信息，不能与/svc或/m同时使用。

* 【命令】`taskkill`：用于结束多个进程。

  ```cmd
  taskkill /pid <ProcessID>     # 指定进程ID来终止进程。
  ```

  > * `/s <Computer>`：指定远程计算机名称或IP地址，默认为本地计算机。
  > * `/u <Domain\User>`：指定执行账户，默认为本地的当前用户。
  > * `/p <Password>`：指定账户密码。
  > * `/fi <FilterName>`：指定终止条件。
  > * `/pid <ProcdssID>`：指定终止进程的进程ID。
  > * `/im <ImageName>`：指定终止进程的图像名称，可以使用通配符`*`。
  > * `/f`：强行终止进程，远程所有进程都被强行终止。
  > * `/t`：终止其进程下所有子进程。


### Windows 文件管理

* 【功能】新建文件：

  ```cmd
  notepad <file>                          # 使用记事本打开文件，文件不存在时提示新建文件。
  mkdir <directory>                       # 在指定路径下创建一个目录文件，mkdir可以缩写为md。
  ```

  > Note：在安装vim的前提下，也可以使用vim。

* 【功能】查看文件：

  ```cmd
  type <file>                             # 显示文本内容。
  more <file>                             # 显示文本内容。
  dir                                     # 显示当前路径下所有的文件信息。
  tree                                    # 以树状形式显示当前目录下的文件。
  ```

* 【功能】编辑文件：

  ```cmd
  rename <file> <fileName>                # 修改文件名，rename可以缩写ren。
  attrib <file>                           # 显示文件属性。
  fc <file_1> <file_2>                    # 比较两个文件。
  chdir <directory>                       # 修改当前工作路径,chdir可以缩写为cd。
  # replace <file_1> <file_2>             # 替换文件，可以实现移动文件。
  copy <sourceFile> <destinationFile>     # 复制文件。
  xcopy <sourceFile> <destinationFile>    # 递归复制文件，包括目录文件。
  ```

* 【功能】搜索文件：

  ```cmd
  find "<string>" <filename>   # 在文件中搜索字符串，区分大小写。
  ```

* 【功能】删除文件：

  ```cmd
  del <file>                 # 删除文件。
  erase <file>               # 删除文件。
  rmdir <directory>          # 删除指定路径的目录文件，不能删除隐藏或系统的目录文，rmdir可以缩写为rm。
  ```

* 【功能】新建文件并编辑(<Ctrl+Z>结束编辑): `copy con <filename>`;
* 【功能】单行编辑文件: `echo <content> >> <filename>`;
* 【功能】复制文件: `copy <sourcefile> <destationfile>`;
* 【功能】重命名文件: `rename <fileoldname> <filenewname>`;
* 【功能】删除文件: `del <filename>`;
* 【功能】替换文件: `replace <sourcefilename> <destationfilename>`;
* 【功能】显示文本: `type <filename>` or `more <filename> # 多页显示`;
* 【功能】搜索文件中字符: `find <string> <filename>`;
* 【功能】比较两个文件: `fc <filename1> <filename2>`;

#### 目录管理

* 【功能】新建目录: `mkdir <directoryname>`;
* 【功能】切换当前工作目录: `chdir <directoryname>`;
* 【功能】删除目录: `rmdir <directoryname>`;
* 【功能】修改文件目录属性: `attrib <directoryname or filename>`;
* 【功能】显示当前目录的所有文件和目录: `dir`;
* 【功能】复制所有文件及目录: `xcopy <sourcepath> <destationpath>`;

### Windows 用户管理

Windows的账户由用户及用户组组成。

* 用户配置信息`C:\windows\system32\config\SAM`;

#### 用户的管理

* 【功能】新建用户：

  ```cmd
  @rem 添加普通用户。
  net user /add <userName> <password>
  @rem 将普通用户添加到管理员组。
  net localgroup administrators /add <userName> <password>
  ```

* 【功能】查看用户信息：

  ```cmd
  @rem 查看当前用户。
  whoami
  @rem 查看所有用户。
  net user
  ```

* 【功能】修改用户信息：

  ```cmd
  @rem 修改用户密码。
  net user <username> <newpassword>
  @rem 禁用用户。
  net user <username> /active:no
  ```

* 【功能】删除用户：

  ```cmd
  net user /delete <userName>                       # 删除用户
  net localgroup administrators /delete <userName>  # 从管理员组中去除用户
  ```

  > Note： 密码保存在SAM文件中。

#### 用户组管理

* 【功能】新建组:`net localgroup <groupname> /add`;
* 【功能】管理组:`net localgroup <groupname> <username> /del`;
* 【功能】
* 【功能】
* 【功能】
* 【功能】

* 用户账户: administrator、guest;
* 计算机服务组件相关的系统账号: system、local services、network services;
* 内置组: administrators、guests、users、network、print、Remote Desktop;




### Windows 电源管理

* 【功能】关闭计算机：

  ```cmd
  shutdowm
  ```

* 【功能】注销登录用户：

  ```cmd
  @rem 注销用户登录。
  logooff
  ```

### Windows 环境变量

* 【功能】日常使用命令：

  ```cmd
  @rem 启动一个应用程序。
  start
  @rem 用于撤销Windows命令，调用Windows命令并创建宏，可以实现脚本间历史命令的传输。
  doskey
  @rem 退出cmd程序。
  exit
  ```

* 【功能】终端主题配置：

  ```cmd
  @rem 设置窗口标题。
  title <new title name>
  @rem 设置窗口颜色。
  color 0A
  @rem 定制个性化提示符。
  prompt
  ```

  > Note:这些工具保存在C:\Windows与\C:\Windowssystem32中

* 【功能】设置环境变量：

  ```cmd
  @rem 管理指定环境变量，退出后失效。
  set <variable>=<value>
  @rem 设置path变量，退出后失效。
  path
  ```

### Windows 自启动项

开机启动项是在计算机系统启动时自动执行的程序，其主要存在以下几个地方。

* 系统（用户）启动文件夹：系统启动文件夹在。
* 注册表启动项`计算机\HKEY_CURRENT_USER\Software\Microsoft\Windows NT\CurrentVersion\Windows\load`主键；
* 注册表启动项`计算机\HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon\Userinit`主键；
* 注册表启动项`计算机\HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\Run`主键；
* 注册表启动项`计算机\HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\Explorer\Run`主键；
* 注册表启动项`计算机\HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\RunOnce`主键；
* 注册表启动项`计算机\HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\RunOnce`主键；
* 注册表启动项`计算机\HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run`主键；
* 注册表启动项`计算机\HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run`主键；

### Windows 策略

组策略是将系统重要的配置功能汇集成各种配置模块,供管理人员直接使用，从而达到方便管理计算机的目的。是系统策略的更高级的扩展。
gpedit.msc

* 手动更新计算机组策略`gpupdate /target:computer`

### Windows 注册表

注册表实质是一个庞大的数据库，存储了关于计算机硬件的全部配置信息、系统和软件的初始化信息、应用软件和文档文件的关联关系、硬件设备的说明以及各种状态信息和数据；注册表编辑器Regedit是管理注册表的工具。注册表由五大根键、子健、键值项、键值，在win98中将子健称为主键。

* `HKEY_CLASES_ROOT`：包含启动应用程序所需要的全部信息。
* `HKEY_CURRENT_USER`：管理与当前登录用户有关的信息。
* `HKEY_LOCAL_MACHINE`：保存了Windows的信息，包含了应用程序、驱动程序以及硬件信息。
* `HKEY_USERS`：包含所有的用户配置文件的前活动用户信息。
* `HKEY_CURRENT_CONFIG`：是HKEY_LOCAL_MACHINE的映射，

#### 基础键值项

| 键值项 | 主键 | 类型 | 键值 | 说明 |
|:------:|:---- |:---:|:---- |:---- |
| InitialKeyboardIndicators | HKEY_USERS\\.DEFAULT\Control Panel\Keyboard | REG_SZ | {0,2} | 让<kbd>NumLock</kbd>登录后自动开启,0表示关闭,2表示开启 |
| WaitTokillAppTimeOut | HKEY_USERS\\.DEFAULT\Control Panel\Desktop | REG_SE | (0,2000) | 设置"关闭无响应程序"的等待时间 |
| IoPageLockLimit | HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\Session Manager\Memory Management | DWORD | (0,4000) | IO缓存大小 |

### cmd

计算机\HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Command Processor\autorun

#### Diretx

* `dxdiag`

#### Administrator

`计算机\HKEY_LOCAL_MACHINE\SAM\SAM`

* Windows 1998登录时点击取消直接进入系统的解决：在`HKEY_LOCAL_MACHINE\Network\Logon`新建DWORD的`MustBeValidated`，值为1；`HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Winogon`新建一个DWORD的`MustBeValidated`，值为1；并在Msdos.sys中增加`BootFailSafe=0`来禁止安全模式；即可完成登录时必须输入密码。
* NumLock键登录时开启`HKEY_USERS\.DEFAULT\Control Panel\Keyboard`修改`InitialKeyboardIndicators`值为2，为0时关闭。
* 系统还原功能`HKET_LOCAL_MACHINE\Software\Policies\Microsoft\WindowsNT\SystemRestore`中的`DisableSR`，值为1时开启，0时关闭。
* 磁盘不足警告的临界值`HKEY_LOCAL_MACHINE\System\CurrentControlSet\Services\LanmanServer\Parameters`中的`DiskSpaceThreshold`的百分比值，默认为10（10%）。
* 磁盘不足时无警告`HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer`中的`NoLowDiskSpaceChecks`，值为1时启用，0时关闭。
* 媒体设备自动运行`HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer`中的`NoDriveTypeAutoRun`，255时所有驱动器，181时CD-ROM驱动器。
* 自动保存桌面`HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer`中的`NoSaveSettings`，0时关闭，1时开启。
* 自动登录`HKEY_LOCAL_MACHINE\Software\Microsoft\WindowsNT\CurrentVersion\Winlogon`中的`AutoAdminLogon`为1时启动自动登录，`DefaultDomainName`设置默认域名，`DefaultUserName`设置默认用户名，`DefaultPassword`设置默认密码。
* 禁止当前用户访问驱动器`HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer`中的`NoViewOnDrive`，8时限制D盘。
* 隐藏驱动器`HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer`中的`NoDrive`,值为8时隐藏D盘。
* 屏蔽任务栏设置`HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer`中的`NoSetTaskbar`为1时屏蔽设置中的任务栏设置。
* 屏蔽运行与搜索窗口`HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer`中的`NoRun`为1屏蔽运行，`NoFind`为1屏蔽搜索，`NoClose`为1屏蔽关闭计算机。
* 禁止修改系统字体大小`HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\System`中的`NoSizeChoice`为1。
* 隐藏修改系统显示属性`HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\System`中的`NoDisAppearancePage`为1隐藏外观，`NoDispScrSavPage`为1隐藏屏幕保护程序，`NoDispSettingPage`为1隐藏桌面、主题、设置，`NoDispCPL`为1时隐藏显示组件。
* 禁止修改桌面背景`HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\ActiveDesktop`中的`NoChangingWallPaper`为1禁用。
* 禁止修改系统主题`HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Expolorer`中的`NoThemesTab`为1禁用。
* 隐藏控制面板`HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer`中的`NoControlPanel`为1时隐藏。



## Windows 启动流程

### Windows XP 启动原理

1. 预启动：BIOS扫描硬件配置，读取MBR，检查DPT
2. 启动
3. 装载内核：
4. 初始化内核：
5. 用户登录：

* Cleanmgr与超级魔法兔子

* 图标：iconfactory

* 鼠标

* 窗口

* 对话框

* 向导



## LINKS

* [Windows 官方网站](https://www.microsoft.com/zh-cn/windows/)
  > <https://www.microsoft.com/zh-cn/windows/>

* [Windows 下载官方资源](https://www.microsoft.com/zh-cn/software-download)
   > <https://www.microsoft.com/zh-cn/software-download>