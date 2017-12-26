#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char a[100][100];
	char b[10][10];//存放子串
	int t;
	int x;
	scanf("%d", &x);//有x个单词
	int i, j;
	for (i = 0; i < x; i++)
	{
		scanf("%s", a[i]);
	}
	//输入单词
	int z, y, s, w;
	int k = 0;
	int flag = 1;
	int flag1 = 0;
	int p, q;
	int len;//长度
	int max = 0;
	char c[10];//临时存放
	for (w = 0; a[0][w] != '\0'; w++)
		for (y = w; a[0][y] != '\0'; y++)//遍取所有子串
		{
			flag = 1;
			len = y - w + 1;
			int g = len;
			for (s = 0; s <= (y - w); s++, g--)
			{
				c[s] = a[0][y - g + 1];
			}
			c[s] = '\0';

			for (z = 1; z < x; z++)
			{
				if (strstr(a[z], c) == NULL)
					flag = 0;
			}
			if (flag == 1)
			{
				flag1 = 1;
				if (max < len)
				{
					k = 0;
					max = len;
					for (t = 0; t < max; t++)
						b[k][t] = c[t];
					b[k][t] = '\0';
				}
				else if (max == len)
				{
					k++;
					for (t = 0; t < max; t++)
						b[k][t] = c[t];
					b[k][t] = '\0';
				}
			}
		}
	if (flag1 == 0)
		printf("error");
	else
	{
		char e[10];
		for (i = 0; i <= k; i++)
			for (j = 0; j <= k; j++)
			{
				if (strcmp(b[i], b[j]) < 0)
				{
					strcpy(e, b[i]);
					strcpy(b[i], b[j]);
					strcpy(b[j], e);
				}
			}
		for (p = 0; p <= k; p++)
		{
			for (i = 0; i < max; i++)
				printf("%c", b[p][i]);
			printf("\n");
		}
	}
	return 0;
}