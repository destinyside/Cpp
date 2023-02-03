#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
int longestValidParentheses1(char *s)
{
    int len = strlen(s);
    if (len <= 2)
    {
        if (strcmp(s, "()") == 0)
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
    int left = 0, right = 0;
    int max = 0, maxi = 0, maxj = 0;
    int i = 0;
    while (left < 0 && right > 0)
    {
        if (s[left] == '(' && s[right] == ')')
        {
            while (left > 0)
            {
            }
        }
    }
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(' && s[i + 1] == ')')
        {
            left = i - 2;
            while (left >= 0 && (s[left] == '(' && s[left + 1] == ')'))
            {
                left -= 2;
            }
            left++;
            right = i + 3;
            while (right < len && (s[right] == ')' && s[right - 1] == '('))
            {
                right += 2;
            }
            right--;
            while (left >= 0 && right < len && (s[left] == '(' && s[right] == ')'))
            {
                left--;
                right++;
            }
            printf("l %d r %d\n", left, right);
            int p = left + 1;
            int q = right - 1;
            if (q - p > max)
            {
                if (p == maxj + 1)
                {
                    max += q - p + 1;
                    maxj = q;
                }
                else
                {
                    maxi = p;
                    maxj = q;
                    max = q - p + 1;
                }
                printf("max %d maxi %d maxj %d\n", max, maxi, maxj);
            }
            else if (p == maxj + 1)
            {
                max += q - p + 1;
                maxj = q;
            }
        }
    }
    return max;
}
*/

int longestValidParentheses(char *s)
{
    int len = strlen(s);
    int max = 0;
    //int *stack = malloc(sizeof(int) * (len + 10));
    int stack[len+10];
    stack[0] = -1;
    int top = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(')
        {
            stack[++top] = i;
        }
        else
        {
            if (top >= 0)
            {
                top--;
            }
            if (top < 0)
            {
                stack[++top] = i;
            }
            else
            {
                int m = i - stack[top];
                max = max > m ? max : m;
            }
        }
    }
    //free(stack);
    return max;
}

void t(char *s)
{
    printf("s:%s\nl:%d\n", s, longestValidParentheses(s));
}

int main(int argc, char *argv[])
{
    FILE *fp = NULL;

    fp = fopen("patterns.txt", "r");
    if (fp == NULL)
    {
        perror("open file error");
        return -1;
    }
    char ch;
    char *s = malloc(sizeof(char) * 120);

    int i = 0, j = 0;
    int c = 0;
    int f = 0;
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '!')
        {
            break;
        }
        if (ch != '\n')
        {
            s[i++] = ch;
        }
        else
        {
            s[i] = '\0';
            f++;
            c = 1;
        }
        if (f == 1)
        {
            t(s);
            f = 0;
            c = 0;
            i = 0;
            j = 0;
        }
    }
    free(s);
    fclose(fp);
    return EXIT_SUCCESS;
}
