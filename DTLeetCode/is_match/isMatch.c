#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isMatch3(char * s, char * p){
    if(!*p)
    return !*s;
    bool first_me = *s && (*s==*p||*p=='.');
    if(*(p+1)=='*')
    {
        return isMatch3(s, p+2)||(first_me&&isMatch3(++s, p));
    }
    else return first_me && isMatch3(++s,++p);
}

bool isMatch2(char * s, char * p){
  char c;
  char d;
  while (*p) {
    c = *p;
    ++p;
    if (*p && *p == '*') {
      ++p;
      d = *p;
      while (d == c && *(p + 1) && *(p + 1) == '*') {
        p += 2;
        d = *p;
      }
      if (d && isMatch2(s, p)) {
        return true;
      }
      if (c != '.') {
        while (c == *s) {
          if (d && isMatch2(s, p)) {
            return true;
          }
          ++s;
        }
      } else {
        while (*s) {
          if (d && isMatch2(s, p)) {
            return true;
          }
          ++s;
        }
      }
    } else if ((c == '.' && *s) || c == *s) {
      ++s;
    } else {
      return false;
    }
  }
  
  return !(*s);
}

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
			dp[0][j] = dp[0][j - 2];
		}
	}

	for (int i = 1; i <= slen; i++)
	{
		for (int j = 1; j <= plen; j++)
		{
			if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else if (p[j - 1] == '*')
			{
				if (s[i - 1] == p[j - 2] || p[j - 2] == '.')
				{
					dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
				}
				else
				{
					dp[i][j] = dp[i][j - 2];
				}
			}
		}
	}
	return dp[slen][plen];
}

bool isMatch1(char *s, char *p)
{
	char *s1 = s;
	char *p1 = p;
	bool match = false;
	while (true)
	{
		if (*s1 == *p1 || *p1 == '.')
		{
			// printf("12 s1: %c p1: %c\n", *s1 != '\0' ? *s1 : 'n', *p1 != '\0' ? *p1 : 'n');
			if (*s1 != '\0')
			{
				s1++;
			}
			if (*p1 != '\0')
			{
				p1++;
			}
			if (*s1 == '\0' && *p1 == '\0')
			{
				match = true;
				break;
			}
			else if (*p1 == '\0')
			{
				match = false;
				break;
			}
			else if (*p1 == '.')
			{
				match = true;
			}
		}
		else if (*p1 == '*')
		{
			// printf("13 s1: %c p1: %c\n", *s1 != '\0' ? *s1 : 'n', *p1 != '\0' ? *p1 : 'n');
			if (*s1 == '\0')
			{
				if (*(s1 - 1) == *(p1 - 1))
				{
					match = true;
				}
			}
			else if (*(p1 - 1) == '.')
			{
				if (*(p1 + 1) == '\0')
				{
					match = true;
				}
				else
				{
					int slen = strlen(s1);
					for (int i = 0; i < slen; i++)
					{
						match = match || isMatch(s1 + i, p1 + 1);
					}
				}
			}
			else
			{
				int slen = strlen(s1);
				int i = 0;
				for (; i < slen; i++)
				{
					if (*(s1 + i) == *(p1 - 1))
					{
						match = true;
					}
					else
					{
						break;
					}
				}
				s1 += i;
			}
			p1++;
		}
		else
		{
			// printf("14 s1: %c p1: %c\n", *s1 != '\0' ? *s1 : 'n', *p1 != '\0' ? *p1 : 'n');
			if (*p1 != '\0' && *(p1 + 1) == '*')
			{
				p1 += 2;
			}
			else
			{
				break;
			}
		}
	}
	return match;
}

void t(char *s, char *p)
{
	printf("s:%s\np:%s\nmatch:%s\n", s, p, isMatch(s, p) ? "true" : "false");
}

int main(int argc, char *argv[])
{
	FILE *fp = NULL;

	fp = fopen("regex_patterns.txt", "r");
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
