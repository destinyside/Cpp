#include <stdio.h>
#include <stdlib.h>
/**
    2 1 1    1
    2 2 2    1
    2 3 3    1
    2 4 4    1
    m n f(n)=n,f(1)=1

    3 1 1  1
    3 2 3  2
    3 3 6  3
    3 4 10 4
    3 5 15 5
    3 6 21 6
    3 7 28 7
    m n f(3, n)=f(2, n)+(3,n - 1)

    4 1 1  1
    4 2 4  3
    4 3 10 6
    4 4 20 10
    4 5 35 15
    4 6 56 21
    4 7 84 28
    m n f(4, n)=
    m n f(m,n)=f(m-1,n)+f(m,n-1);
*/

int pathMap(int **dp, int m, int n)
{
    if (dp[m][n])
    {
        return dp[m][n];
    }
    else
    {
        if (m == 1 || n == 1)
        {
            dp[m][n] = 1;
            return 1;
        }
        else if (m == 2)
        {
            dp[m][n] = n;
            return n;
        }
        else if (n == 2)
        {
            dp[m][n] = n;
            return m;
        }
        else
        {
            int val = pathMap(dp, m - 1, n) + pathMap(dp, m, n - 1);
            dp[m][n] = val;
            return val;
        }
    }
}

int uniquePaths(int m, int n)
{
    int *dp[m + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[i] = malloc(sizeof(int) * (n + 1));
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = 0;
        }
    }
    int res = pathMap(dp, m, n);
    for (int i = 0; i <= m; i++)
    {
        free(dp[i]);
    }
    return res;
}

int main()
{
    int m = 16, n = 16;
    printf("m %d n %d mn %d\n", m, n, uniquePaths(m, n));
    return 0;
}