#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main(int args, char *argv[])
{
	if (strcmp(argv[1], "-c")==0)
	{
		int charnum = 0;
		FILE* fp = NULL;
		char c;
		fp = fopen(argv[2], "r");
		if (fp == NULL)
		{
			printf("该文件名无效\n");
			return 0;			
		}
		c = getc(fp); 
		while (c != EOF)
		{
			c = getc(fp);
			charnum++;
		}
		printf("字符数：%d\n", charnum);
	}
	else if (strcmp(argv[1],"-w")==0)
	{
		int wordnum = 0;
		FILE* fp = NULL;
		char c;
		fp = fopen(argv[2], "r");
		if (fp == NULL)
		{
			printf("该文件名无效\n");
			return 0;
		}
		c = getc(fp);
		while (c != EOF)
		{
			if (c == ' ' || c == ','||c=='\n')
			{
				wordnum++;
				c = getc(fp);
			}
			c = getc(fp);
		}
		if (c != ' ' &&c != ',' &&c != '\n')
			printf("单词数：%d\n", wordnum + 1);
		else
			printf("单词数：%d\n", wordnum);
	}
	else
	{
		printf("参数输入错误\n");
		return 0;
	}
	return 0;
}