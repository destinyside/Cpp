
#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getRow(int rowIndex, int *returnSize)
{
    *returnSize = rowIndex + 1;
    int *arr = malloc(sizeof(int *) * *returnSize);
    if (rowIndex == 0)
    {
        arr[0] = 1;
    }
    else if (rowIndex == 1)
    {
        arr[0] = 1;
        arr[1] = 1;
    }
    else
    {
        arr[0] = 1;
        arr[*returnSize - 1] = 1;
        int lastSize = 0;
        int *lastArr = getRow(rowIndex - 1, &lastSize);
        int j = 1;
        for (int i = 0; i < lastSize - 1; i++)
        {
            arr[j] = lastArr[i] + lastArr[i + 1];
            j++;
        }
        free(lastArr);
    }
    return arr;
}

int *getRow1(int rowIndex, int *returnSize)
{
    *returnSize = rowIndex + 1;
    int *num = (int *)malloc((rowIndex + 1) * sizeof(int));
    for (int i = 0; i <= rowIndex; i++)
        for (int j = i; j >= 0; j--)
        {
            printf("i %d j %d numi %d numj %d\n", i, j, num[i], num[j]);
            if (j == 0 || j == i)
                num[j] = 1;
            else
                num[j] = num[j] + num[j - 1];
        }
    return num;
}

int *getRow2(int rowIndex, int *returnSize)
{
    *returnSize = rowIndex + 1;
    int *arr = malloc(sizeof(int *) * *returnSize);
    arr[0] = 1;
    for (int i = 0; i <= rowIndex; i++)
    {
        arr[i] = 1;
        for (int j = i - 1; j > 0; j--)
        {
            arr[j] = arr[j] + arr[j - 1];
        }
    }
    return arr;
}

int *getRow3(int rowIndex, int *returnSize)
{
    *returnSize = rowIndex + 1;
    int *arr = malloc(sizeof(int *) * *returnSize);
    arr[0] = 1;
    arr[rowIndex] = 1;
    for (int i = 1; i < rowIndex; i++)
    {
        arr[i] = (int)(1.0l*arr[i-1]*(rowIndex - i + 1)/i);
    }
    return arr;
}

int main()
{
    int rowIndex = 33;
    for (int i = 0; i < rowIndex; i++)
    {
        int len = 0;
        int *arr = getRow3(i, &len);
        printf("%d: \n", i);
        for (int j = 0; j < len; j++)
        {
            printf("%d ", arr[j]);
        }
        printf("\n");
        free(arr);
    }
    return 0;
}