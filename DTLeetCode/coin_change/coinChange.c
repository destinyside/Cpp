#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 21

void quicksort(int *p, int left, int right)
{
	if (left > right)
	{
		return;
	}
	int sign = p[left];
	int i = left;
	int j = right;
	while (i != j)
	{
		while (sign < p[j] && i < j)
		{
			j--;
		}
		if (j > i)
		{
			p[i] = p[j];
		}
		while (sign >= p[i] && i < j)
		{
			i++;
		}
		if (i < j)
		{
			p[j] = p[i];
		}
	}
	p[i] = sign;
	quicksort(p, left, i - 1);
	quicksort(p, i + 1, right);
}

int *amountCount;

int coinChangeCount(int *coins, int coinsSize, int amount)
{
	if (amount < 0)
	{
		return -1;
	}
	if (amount == 0)
	{
		return 0;
	}
	if (amountCount[amount - 1] != 0)
	{
		return amountCount[amount - 1];
	}
	int min = INT_MAX;
	for (int i = 0; i < coinsSize; i++)
	{
		int sub = coinChangeCount(coins, coinsSize, amount - coins[i]);
		if (sub >= 0 && sub < min)
		{
			min = 1 + sub;
		}
	}
	amountCount[amount - 1] = (min == INT_MAX) ? -1 : min;
	return amountCount[amount - 1];
}

int coinChange(int *coins, int coinsSize, int amount)
{
	// quicksort(coins, 0, coinsSize - 1);
	if (amount < 1)
	{
		return 0;
	}
	amountCount = malloc(sizeof(int) * amount);
	return coinChangeCount(coins, coinsSize, amount);
}

void t(int *coins, int coinsSize, int amount)
{
	quicksort(coins, 0, coinsSize - 1);
	printf("coins : ");
	for (int i = 0; i < coinsSize; i++)
	{
		printf("%d ", coins[i]);
	}
	printf("\namount: %d\ncount : %d\n\n", amount, coinChange(coins, coinsSize, amount));
}

int main(int argc, char *argv[])
{
	FILE *fp = NULL;

	fp = fopen("coin_changes.txt", "r");
	if (fp == NULL)
	{
		perror("open file error");
		return -1;
	}
	char ch;
	char *s = malloc(sizeof(char) * 20);
	char *p = malloc(sizeof(char) * 20);

	int i = 0, j = 0;
	int c = 0;
	int f = 0;
	int *coins = malloc(sizeof(int) * 50);
	int coinsSize = 0;
	int amount = 0;
	while ((ch = fgetc(fp)) != EOF)
	{
		if (ch == '!')
		{
			break;
		}

		if (c == 0)
		{
			// 读数组
			if (ch >= '0' && ch <= '9')
			{
				s[i++] = ch;
			}
			else if (ch == '\n')
			{
				s[i] = '\0';
				coins[coinsSize++] = atoi(s);
				f++;
				c = 1;
			}
			else
			{
				s[i] = '\0';
				coins[coinsSize++] = atoi(s);
				i = 0;
			}
		}
		else
		{
			// 读amount
			if (ch != '\n')
			{
				p[j++] = ch;
			}
			else
			{
				p[j] = '\0';
				amount = atoi(p);
				f++;
			}
		}
		if (f == 2)
		{
			t(coins, coinsSize, amount);
			coinsSize = 0;
			amount = 0;
			f = 0;
			c = 0;
			i = 0;
			j = 0;
		}
	}
	free(s);
	free(p);
	free(coins);
	fclose(fp);
	return EXIT_SUCCESS;
}
