#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isMatch(char *s, char *p)
{
	int slen = strlen(s);
	int plen = strlen(p);

	bool dp[slen + 1][plen + 1];
	for (int i = 0; i <= slen; i++)
	{
		for (int j = 0; j <= plen; j++)
		{
			dp[i][j] = false;
		}
	}

	dp[0][0] = true;

	for (int j = 1; j <= plen; j++)
	{
		if (p[j - 1] == '*')
		{
			dp[0][j] = true;
		} else {
			break;
		}
	}

	for (int i = 1; i <= slen; i++)
	{
		for (int j = 1; j <= plen; j++)
		{
			if (p[j - 1] == '*')
			{
				dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
			}
			else if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
		}
	}
	return dp[slen][plen];
}

void t(char *s, char *p)
{
	printf("s:%s\np:%s\nmatch:%s\n", s, p, isMatch(s, p) ? "true" : "false");
}

int main(int argc, char *argv[])
{
	FILE *fp = NULL;

	fp = fopen("regex_patterns1.txt", "r");
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
