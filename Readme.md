本例是将 easylogger 移植到Linux平台的示例，参考了官方的例程

elog_port.c： elog移植接口文件；
elog.c：      elog核心功能源码；
elog_utils.c：elog所用到的一些c库工具函数实现；
elog_buf.c（可选添加）：  elog缓冲输出模式源码；
elog_async.c（可选添加）：elog异步输出模式源码；

elog_file_cfg.h   定义了输出到文件的名称、位置、大小和个数
elog_cfg.h        定义了输出日志的级别和是否输出到文件等信息



/* 使用方法如下： */
#define LOG_TAG "main"
#include "elog.h"

/* 本例的输出结果 */
I/elog     EasyLogger V2.2.99 is initialize success.
A/main     [11-17 14:29:05 pid:6008 tid:14023] (/mnt/share/demo/44-easylog/user/src/main.c main:65)hello elog! i = 0
E/main     hello elog! i = 0
W/main     hello elog! i = 0
I/main     hello elog! i = 0
D/main     (/mnt/share/demo/44-easylog/user/src/main.c main:69)hello elog! i = 0
V/main     [11-17 14:29:05 pid:6008 tid:14023] (/mnt/share/demo/44-easylog/user/src/main.c main:70)hello elog! i = 0
A/main     [11-17 14:29:10 pid:6008 tid:14023] (/mnt/share/demo/44-easylog/user/src/main.c main:65)hello elog! i = 1
E/main     hello elog! i = 1
W/main     hello elog! i = 1
I/main     hello elog! i = 1
D/main     (/mnt/share/demo/44-easylog/user/src/main.c main:69)hello elog! i = 1
V/main     [11-17 14:29:10 pid:6008 tid:14023] (/mnt/share/demo/44-easylog/user/src/main.c main:70)hello elog! i = 1
A/main     [11-17 14:29:15 pid:6008 tid:14023] (/mnt/share/demo/44-easylog/user/src/main.c main:65)hello elog! i = 2
E/main     hello elog! i = 2
W/main     hello elog! i = 2
I/main     hello elog! i = 2
D/main     (/mnt/share/demo/44-easylog/user/src/main.c main:69)hello elog! i = 2
V/main     [11-17 14:29:15 pid:6008 tid:14023] (/mnt/share/demo/44-easylog/user/src/main.c main:70)hello elog! i = 2
A/main     [11-17 14:29:20 pid:6008 tid:14023] (/mnt/share/demo/44-easylog/user/src/main.c main:65)hello elog! i = 3
E/main     hello elog! i = 3
W/main     hello elog! i = 3
I/main     hello elog! i = 3
D/main     (/mnt/share/demo/44-easylog/user/src/main.c main:69)hello elog! i = 3
V/main     [11-17 14:29:20 pid:6008 tid:14023] (/mnt/share/demo/44-easylog/user/src/main.c main:70)hello elog! i = 3
A/main     [11-17 14:29:25 pid:6008 tid:14023] (/mnt/share/demo/44-easylog/user/src/main.c main:65)hello elog! i = 4
E/main     hello elog! i = 4
W/main     hello elog! i = 4
I/main     hello elog! i = 4
D/main     (/mnt/share/demo/44-easylog/user/src/main.c main:69)hello elog! i = 4
V/main     [11-17 14:29:25 pid:6008 tid:14023] (/mnt/share/demo/44-easylog/user/src/main.c main:70)hello elog! i = 4
A/main     [11-17 14:29:30 pid:6008 tid:14023] (/mnt/share/demo/44-easylog/user/src/main.c main:65)hello elog! i = 5
E/main     hello elog! i = 5
W/main     hello elog! i = 5
I/main     hello elog! i = 5
D/main     (/mnt/share/demo/44-easylog/user/src/main.c main:69)hello elog! i = 5
V/main     [11-17 14:29:30 pid:6008 tid:14023] (/mnt/share/demo/44-easylog/user/src/main.c main:70)hello elog! i = 5
^C
linux@linux-VirtualBox:~/share/demo/44-easylog/obj$ ls -l
总用量 52
-rwxrwxrwx 1 root root 39800 11月 17 14:28 app
-rwxrwxrwx 1 root root     0 11月 17 10:09 core
-rwxrwxrwx 1 root root   737 11月 17 14:28 elog_file.log		/* 最新的日志文件 */
-rwxrwxrwx 1 root root  1030 11月 17 14:28 elog_file.log.0		/* 较旧的日志文件 */
-rwxrwxrwx 1 root root  1142 11月 17 14:28 elog_file.log.1		/* 更旧的日志文件 */

