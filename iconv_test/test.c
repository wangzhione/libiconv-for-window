#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sciconv.h>

#define _INT_STR	(35)
#define _STR_NAME	"name.data"

//
// 测试 libiconv.lib 库的使用
// 
int main(void) {

	char name[_INT_STR] = "王志 - simplec";
	printf("[%s] is utf8 = %d.\n", name, si_isutf8(name));
	si_gbktoutf8(name);
	printf("[%s] is utf8 = %d.\n", name, si_isutf8(name));

	// 输出字符串到文本中, 通过UTF-8文本查看编码形式
	FILE * txt = fopen(_STR_NAME, "wb");
	if (NULL == txt) {
		fprintf(stderr, "fopen " _STR_NAME " wb is error!");
		exit(EXIT_FAILURE);
	}
	// 这里将name数据写入到文件中
	fwrite(name, sizeof(char), _INT_STR, txt);
	fclose(txt);

	puts(_STR_NAME " write is success!");

	return EXIT_SUCCESS;
}