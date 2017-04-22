## 静态库：libiconv for window 项目概述

### 简单介绍
    当前移植项目基于 GNU 项目 libiconv-1.15 | http://www.gnu.org/software/libiconv/
    移植到平台 window 10 14393.953 | Visual Studio 2017 
    项目发起人 : simplec - wz | wangzhione@163.com

### 额外补充: 
    iconv_window : 是 libiconv 静态库的项目目录
    更多细节可以参照 : iconv_window/ReadMe.txt
    iconv_test : 是利用静态库构建的一个测试项目. 并构建了一个 sciconv.h 帮助接口, 方便使用.

### 所做的工作:
* 将最新的GNU iconv 1.15 源码移植到 Visual Studio 2017 下
* 修改了(小批量删除)不少编译代码. 
* 解决了所有 warning .....
* 提供一个丑陋的 sciconv.h 的帮助接口 (好过没有不是吗)

###  api helper

```c
#include <sciconv.h>
#define _INT_STR	(35)

char name[_INT_STR] = "还在 - simplec";
printf("[%s] is utf8 = %d.\n", name, si_isutf8(name));
si_gbktoutf8(name);
printf("[%s] is utf8 = %d.\n", name, si_isutf8(name));
```

    更加详细的可以参照, iconv_test/iconv/include/sciconv.h

### << 江 (ㅍ_ㅍ) 南 >>
    江南可采莲，莲叶何田田。鱼戏莲叶间。鱼戏莲叶东，鱼戏莲叶西，鱼戏莲叶南，鱼戏莲叶北。
