#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
	int ch, count = 1;
	FILE* fp;
	if ((fp = fopen(argv[2], "r")) == NULL)
    {
		printf("USEAGE:\nwordcount [parameter] [input_file_name]\n[parameter]:-c计算字母数；-w计算单词数\n[input_file_name]：文件名\n");
		exit(1);
	}
	if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "-C") == 0)
    {
		count = 0;
		while ((ch = getc(fp)) != EOF)
        {
			count++;
		}
		printf("共计%d个字符\n", count);
	}
	else if (strcmp(argv[1], "-w") == 0 || strcmp(argv[1], "-W") == 0)
    {
		while ((ch = getc(fp)) != EOF)
        {
			if ((ch == ' ') || (ch == ',') || (ch == '.') || (ch == ';'))
            {
				count++;
			}
		}
		printf("共计%d个单词\n", count);
	}
	else
    {
		printf("USEAGE:\nwordcount [parameter] [input_file_name]\n[parameter]:-c计算字母数；-w计算单词数\n[input_file_name]：文件名\n");
	}
	fclose(fp);
	return 0;
}