#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *longestPalindrome1(char *s)
{
	int slen = strlen(s);
	if (slen == 1)
	{
		return s;
	}
	int dp[slen + 1][slen + 1];
	for (int i = 0; i <= slen; i++)
	{
		for (int j = 0; j <= slen; j++)
		{
			dp[i][j] = 0;
		}
	}
	int max = 0, maxi = 0, maxj = 0;
	for (int i = 0; i < slen; i++)
	{
		for (int j = i; j < slen; j++)
		{
			bool match = true;
			for (int k = i, l = j; k <= l; k++, l--)
			{
				if (s[k] != s[l])
				{
					match = false;
					break;
				}
			}
			if (match)
			{
				dp[i][j] = j - i + 1;
				if (dp[i][j] > max)
				{
					max = dp[i][j];
					maxi = i;
					maxj = j;
					printf("max %d maxi %d maxj %d \n", max, maxi, maxj);
				}
			}
		}
	}
	char *p = malloc(sizeof(char) * (max + 1));
	for (int i = maxi, j = 0; i <= maxj; i++, j++)
	{
		p[j] = s[i];
	}
	p[max] = '\0';
	return p;
}

char *longestPalindrome2(char *s)
{
	int slen = strlen(s);
	if (slen == 1)
	{
		return s;
	}
	int max = 0, maxi = 0, maxj = 0;
	for (int i = 0; i < slen; i++)
	{
		int l = i - 1;
		int r = i + 1;
		while (l >= 0 && s[l] == s[i])
		{
			l--;
		}
		while (r < slen && s[r] == s[i])
		{
			r++;
		}
		while (l >= 0 && r < slen && s[l] == s[r])
		{
			l--;
			r++;
		}
		if (r - l - 1 > max)
		{
			max = r - l - 1;
			maxi = l + 1;
			maxj = r - 1;
			printf("max %d maxi %d maxj %d \n", max, maxi, maxj);
		}
	}
	char *p = malloc(sizeof(char) * (max));
	for (int i = maxi, j = 0; i <= maxj; i++, j++)
	{
		p[j] = s[i];
	}
	p[max] = '\0';
	return p;
}

char *longestPalindrome(char *s)
{
	int slen = strlen(s);
	if (slen == 1)
	{
		return s;
	}
	int max = 0, maxi = 0, maxj = 0;
	for (int i = 0; i < slen; i++)
	{
		int l = i - 1;
		int r = i + 1;
		while (l >= 0 && s[l] == s[i])
		{
			l--;
		}
		while (r < slen && s[r] == s[i])
		{
			r++;
		}
		while (l >= 0 && r < slen && s[l] == s[r])
		{
			l--;
			r++;
		}
		if (r - l - 1 > max)
		{
			max = r - l - 1;
			maxi = l + 1;
			maxj = r - 1;
			printf("max %d maxi %d maxj %d \n", max, maxi, maxj);
		}
	}
	char *p = malloc(sizeof(char) * (max));
	for (int i = maxi, j = 0; i <= maxj; i++, j++)
	{
		p[j] = s[i];
	}
	p[max] = '\0';
	return p;
}

void t(char *s)
{
	printf("s:%s\nsub:%s\n", s, longestPalindrome(s));
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
	char *s = malloc(sizeof(char) * 120);

	int i = 0, j = 0;
	int c = 0;
	int f = 0;
	while ((ch = fgetc(fp)) != EOF)
	{
		if (ch == '!')
		{
			break;
		}
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
		if (f == 1)
		{
			t(s);
			f = 0;
			c = 0;
			i = 0;
			j = 0;
		}
	}
	free(s);
	fclose(fp);
	return EXIT_SUCCESS;
}
