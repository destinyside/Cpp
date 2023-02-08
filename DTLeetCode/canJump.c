#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool jump1(int *nums, int numsSize, int *dp, int pos)
{
    if (pos == numsSize - 1)
    {
        return true;
    }
    else if (pos >= numsSize)
    {
        return false;
    }
    else
    {
        if (dp[pos] != -1)
        {
            return dp[pos] == 1;
        }
        else
        {
            bool can = false;
            for (int i = 1, len = nums[pos]; i <= len; i++)
            {
                if (pos + i <= numsSize - 1)
                {
                    if (dp[pos + i] == -1)
                    {
                        dp[pos + i] = jump1(nums, numsSize, dp, pos + i);
                    }
                    can = can || dp[pos + i];
                }
            }
            return can;
        }
    }
}

bool canJump1(int *nums, int numsSize)
{
    int *dp = malloc(sizeof(int) * (numsSize + 1));
    for (int i = 0; i < numsSize + 1; i++)
    {
        dp[i] = -1;
    }
    bool res = jump1(nums, numsSize, dp, 0);
    free(dp);
    return res;
}

int fmax(int a, int b)
{
    return a > b ? a : b;
}

bool canJump2(int *nums, int numsSize)
{
    int k = 0;
    for (int i = 0; i <= k; i++)
    {
        k = fmax(i + nums[i], k);
        if (k >= numsSize - 1)
        {
            return true;
        }
    }
    return false;
}

bool canJump(int *nums, int numsSize)
{
    int cur = nums[0];
    int pos = 1;
    if (cur > 0)
    {
        for (; pos < numsSize; pos++)
        {
            if (cur == 0)
            {
                break;
            }
            else
            {
                cur--;
                if (cur < nums[pos])
                {
                    cur = nums[pos];
                }
            }
        }
    }
    return cur >= numsSize - pos;
}

#define NUM_MAX 99999999

int min(int a, int b)
{
    return a < b ? a : b;
}

int jump(int *nums, int numsSize)
{
    int *dp = malloc(sizeof(int) * (numsSize + 1));
    for (int i = 0; i < numsSize + 1; i++)
    {
        dp[i] = NUM_MAX;
    }
    dp[0] = 0;
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1, len = i + 1 + nums[i]; j < len; j++)
        {
            if (j < numsSize)
            {
                dp[j] = min(dp[j], 1 + dp[i]);
            } else {
                break;
            }
            //printArray(dp, numsSize + 1);
        }
    }
    int res = dp[numsSize - 1];
    free(dp);
    return res;
}

bool canJump3(int *nums, int numsSize)
{
    int *dp = malloc(sizeof(int) * (numsSize + 1));
    for (int i = 0; i < numsSize + 1; i++)
    {
        dp[i] = NUM_MAX;
    }
    dp[0] = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int len = i + 1 + nums[i];
        for (int j = i + 1; j < len; j++)
        {
            if (j < numsSize)
            {
                dp[j] = min(dp[j], 1 + dp[i]);
            } else {
                break;
            }
            //printArray(dp, numsSize + 1);
        }
        if(len >= numsSize){
            break;
        }
    }
    int res = dp[numsSize - 1];
    free(dp);
    return res != NUM_MAX;
}

void printArray(int *nums, int numsSize)
{
    printf("[");
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d,", nums[i]);
    }
    printf("]\n");
}

int *randomArray(int len)
{

    srand((unsigned)time(0));
    int *tmp = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
    {
        tmp[i] = rand() % len;
    }
    return tmp;
}

int main()
{
    int len = 10;
    int *arr = randomArray(len);
    printArray(arr, len);
    printf("can jump: %s, jump: %d\n", canJump3(arr, len) ? "true" : "false", jump(arr, len));
    free(arr);
    return 0;
}