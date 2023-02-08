
#include <stdio.h>
#include <stdlib.h>
/**
 * 0  0 00
 * 1  1 01
 * 2  1 10
 * 3  2 11
 * 4  1 100
 * 5  2 101
 * 6  2 110
 * 7  3 111
 * 8  1 1000
 * 9  2 1001
 * 10 2 1010
 */

int power(int b, int i)
{
    if (i == 0)
    {
        return 1;
    }
    else
    {
        int s = 1;
        while (i > 0)
        {
            s *= b;
            i--;
        }
        return s;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countBits(int n, int *returnSize)
{
    *returnSize = n + 1;
    int *arr = (int *)malloc(sizeof(int) * *returnSize);
    arr[0] = 0;
    int t = 1;
    int b = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i >= power(2, b))
        {
            t *= 2;
            b++;
        }
        arr[i] = 1 + arr[i - t];
        // printf("i %d t %d a %d\n", i, t, arr[i]);
    }
    return arr;
}

int main()
{
    int n = 20;
    for (int i = 0; i < n; i++)
    {
        int len = 0;
        int *arr = countBits(i, &len);
        printf("n: %d\nbits: ", i);
        for (int j = 0; j < len; j++)
        {
            printf("%d ", arr[j]);
        }
        printf("\n");
        free(arr);
    }
    printf("%d %d %d\n", 10, 9 , 10 & 9);
    return 0;
}