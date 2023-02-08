#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int maximalRectangle(char **matrix, int matrixSize, int *matrixColSize)
{
    int **dp = malloc(sizeof(int *) * matrixSize);
    for (int i = 0; i < matrixSize; i++)
    {
        *(dp + i) = malloc(sizeof(int) * *matrixColSize);
        for (int j = 0; j < *matrixColSize; j++)
        {
            dp[i][j] = 0;
        }
    }
    int m = 0;
    for (int i = 0; i < matrixSize - 1; i++)
    {
        for (int j = 0; j < *matrixColSize - 1; j++)
        {
            if (matrix[i][j] == '1' && matrix[i + 1][j] == '1')
            {
                // int n = max(dp[i][j] + 1, dp[i + 1][j]);
                dp[i][j] += 2;
                dp[i + 1][j] += 2;
            }
            if (matrix[i][j] == '1' && matrix[i][j + 1] == '1')
            {
                // int n = max(dp[i][j] + 1, dp[i][j + 1]);
                dp[i][j] += 2;
                dp[i][j + 1] += 2;
            }
        }
    }
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < *matrixColSize; j++)
        {
            printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < matrixSize; i++)
    {
        free(*(dp + i));
    }
    free(dp);
    return m;
}

int main()
{
    char *matrix[5] = {
        "10100",
        "10111",
        "11111",
        "10010"};
    int row = 4;
    int col = 5;
    printf("row %d col %d max %d\n", row, col, maximalRectangle(matrix, row, &col));
    return EXIT_SUCCESS;
}