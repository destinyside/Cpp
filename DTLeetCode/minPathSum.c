#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

/**
 * 
[[1,3,1,7],
 [1,4,5,1],
 [4,3,2,1],
 [2,3,1,5]]
*/
int minPathSum(int **grid, int gridSize, int *gridColSize)
{
    int dp[gridSize + 1][*gridColSize + 1];
    dp[0][0] = grid[0][0];
    for (int i = 1; i < gridSize; i++)
    {
        dp[i][0] = grid[i][0] + dp[i - 1][0];
    }
    for (int j = 1; j < *gridColSize; j++)
    {
        dp[0][j] = grid[0][j] + dp[0][j - 1];
    }
    for(int i=0; i<*gridColSize; i++){
        printf("%d\t", dp[0][i]);
    }
    printf("\n");
    for (int i = 1; i < gridSize; i++)
    {
        printf("%d\t",dp[i][0]);
        for (int j = 1; j < *gridColSize; j++)
        {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }
    return dp[gridSize - 1][*gridColSize - 1];
}

int main()
{
    int grid1[4][4] = {
        {1,3,1,7},
        {1,4,5,1},
        {4,3,2,1},
        {2,3,1,5}
    };

    srand((unsigned)time(0));
    int m = 4, n = 4;
    int **grid = malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++)
    {
        *(grid + i) = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = grid1[i][j];
            //rand() % 20;
            printf("%d\t", grid[i][j]);
        }
        printf("\n");
    }
    int num = minPathSum(grid, m, &n);
    for (int i = 0; i < m; i++)
    {
        free(*(grid + i));
    }
    free(grid);
    printf("m %d n %d mn %d\n", m, n, num);
    return 0;
}