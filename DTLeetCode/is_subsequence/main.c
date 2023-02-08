#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isSubsequence(char *s, char *t)
{

	char *p = t;
	char *q = s;
	if (*q == '\0')
	{
		return true;
	}
	while (*p != '\0')
	{
		if (*p == *q)
		{
			p++;
			q++;
			if (*q == '\0')
			{
				return true;
			}
		}
		else
		{
			p++;
		}
	}
	return false;
}

void t(char *s, char *p)
{
	printf("s:%s\np:%s\nmatch:%s\n", s, p, isSubsequence(s, p) ? "true" : "false");
}

int main(int argc, char *argv[])
{
	FILE *fp = NULL;

	fp = fopen("patterns.txt", "r");
	if (fp == NULL)
	{
		perror("open file error");
		return -1;
	}
	char ch;
	char *s = malloc(sizeof(char) * 100);
	char *p = malloc(sizeof(char) * 100);

	int i = 0, j = 0;
	int c = 0;
	int f = 0;
	while ((ch = fgetc(fp)) != EOF)
	{
		if (ch == '!')
		{
			break;
		}
		if (c == 0)
		{
			if (ch != '\n')
			{
				s[i++] = ch;
			}
			else
			{
				s[i] = '\0';
				f++;
				c = 1;
			}
		}
		else
		{
			if (ch != '\n')
			{
				p[j++] = ch;
			}
			else
			{
				p[j] = '\0';
				f++;
			}
		}
		if (f == 2)
		{
			t(s, p);
			f = 0;
			c = 0;
			i = 0;
			j = 0;
		}
	}
	free(s);
	free(p);
	fclose(fp);
	return EXIT_SUCCESS;
}