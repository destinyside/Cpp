#include <stdio.h>
#include <stdlib.h>
#define MAX_COST 999999999
#define min(a, b) a < b ? a : b

int minCostClimbingStairs(int *cost, int costSize)
{
    int cost1=0,cost2=0;
    int sum;
    for (int i = 2; i <= costSize; i++)
    {
        sum = min(cost1 + cost[i - 1], cost2 + cost[i - 2]);
        cost2 = cost1;
        cost1 = sum;
    }
    return sum;
}

int main()
{

    int len = 10;
    int arr[10] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    printf("cost %d\n", minCostClimbingStairs(arr, len));
    return 0;
}