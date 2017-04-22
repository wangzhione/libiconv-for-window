========================================================================
    静态库：libiconv for window 项目概述
========================================================================

/////////////////////////////////////////////////////////////////////////////

当前移植项目基于 GNU 项目 libiconv-1.15 | http://www.gnu.org/software/libiconv/

移植到平台 window 10 14393.953 | Visual Studio 2017 

项目发起人 : simplec - wz | wangzhione@163.com

/////////////////////////////////////////////////////////////////////////////

具体操作思路:
	1. 从官网下载资源 libiconv压缩包, 并解压 [xxx = 解压后的详细path]

	2. 在 $(ProjectDir) 项目目录下, 新建 include 目录
		2.1 将压缩包中 xxx/include/iconv.h.build.in 复制到 include 目录下, 并重名为 iconv.h
		2.2 将 xxx/onfig.h.in 复制到 include 下, 名为 config.h
		2.3 将 xxx/lib 下 所有 *.h and *.def 文件复制到 include 目录下
		2.4 将 xxx/libcharset/include/localcharset.h.build.in 复制到 include 目录下, 并改名

	3. 将 xxx/libcharset/lib/localcharset.c 拷贝到 $(ProjectDir) 目录下

	4. 将 xxx/lib/iconv.c 拷贝到 $(ProjectDir) 目录下

	5. 将 localcharset.c iconv.c iconv.h localcharset.h config.h 添加到项目中

	6. VC++ 目录 -> 包含目录 add [$(ProjectDir)include] 进去

	7. C/C++ -> 预处理器 -> add _CRT_SECURE_NO_WARNINGS 去掉不安全的调用

	8. 常规 -> 生成目标名 -> 改成 libiconv , Debug下为 libiconvd

详细编译修改步骤:
	1. iconv.h 修改
		1.1 25 - 29 行 删掉, 30行删除无效宏
		1.2 55 - 61 行 删掉
		1.3 后面所有的 LIBICONV_DLL_EXPORTED 删掉 , 可以用全部替换
		1.4 把后面所有的 @ICONV_CONST@ 删掉
			1.4.1 全局删除 ICONV_CONST
		1.5 后面遇到 @xxx@ 大段大段的删除
		1.6 详细参照我最终的文件底版
		1.7 将这个文件编码改成 UTF-8 有 BOM 模式, 我是用NotePad++转换的

	2. localcharset.c 修改
		2.1 79 - 83 行 删掉

	3. localcharset.h 修改
		3.1 20 - 26 行删除
		3.2 31 行 无效宏删除

	4. config.h 修改
		4.1 28 - 30 行 删除, 回归 EILSEQ

	5. 解决百个警告 
		5.1 我这个代码可以做1.15 window lib 库源码项目集

/////////////////////////////////////////////////////////////////////////////
