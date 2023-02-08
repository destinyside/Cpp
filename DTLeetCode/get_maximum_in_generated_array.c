#include <stdio.h>

int maxNum(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int getMaximumGenerated(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        int num[n + 1];
        num[0] = 0;
        num[1] = 1;
        int max = 1;
        for (int i = 1, len = n / 2 + n % 2; i < len; i++)
        {
            num[i * 2] = num[i];
            num[i * 2 + 1] = num[i] + num[i + 1];
            // printf("i %d i+1 %d 2*i %d\n", i/2, (i-1)/2+1, i);
            max = maxNum(max, maxNum(num[i * 2], num[i * 2 + 1]));
        }
        printf("\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", num[i]);
        }
        printf("\n");
        return max;
    }
}

int main()
{
    int n = 90;
    printf("n %d max %d\n", n, getMaximumGenerated(n));
    n = 90;
    printf("n %d max %d\n", n, getMaximumGenerated(n));
    n = 3;
    printf("n %d max %d\n", n, getMaximumGenerated(n));
    n = 7;
    printf("n %d max %d\n", n, getMaximumGenerated(n));
    return 0;
}