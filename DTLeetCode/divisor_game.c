#include <stdio.h>
#include <stdbool.h>

bool divisorGame(int n)
{
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if (n % (i + 1) == 0)
        {
            dp[0][i] = n - (i + 1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (dp[i - 1][j] % (j + 1) == 0)
            {
                dp[i][j] = dp[i - 1][j] - (j + 1);
            }
        }
    }
    return dp[n][n] != 0;
}

int main()
{
    printf("n %d r %s\n", 3, divisorGame(3)?"true":"false");
    return 0;
}