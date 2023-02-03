#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 1 1
 * ()
 * 2 3
 * ()() ()() (())
 * 3 6
 * ()()() ()()() ()(()) (())() ((())) (()())
 * 4
 *
 *
 */
char **map[10];
int maplen[10];

char *catChar(char *a, char *b)
{
    int len1 = strlen(a);
    int len2 = strlen(b);
    int len = len1 + len2 + 1;
    char *str = malloc(sizeof(char) * len);
    char *h = str;
    char *p = a;
    while (p && *p != '\0')
    {
        *str++ = *p++;
    }
    p = b;
    while (p && *p != '\0')
    {
        *str++ = *p++;
    }
    *str = '\0';
    return h;
}

char *addChar(int pos, char *s)
{

    char *p = s;
    if (!p)
    {
        return NULL;
    }
    int len = strlen(p);
    char *str = malloc(sizeof(char) * (len + 3));
    char *h = str;
    int i = 0;
    if (pos == 0)
    {
        *str++ = '(';
        *str++ = ')';
        while (*p != '\0')
        {
            *str++ = *p++;
        }
    }
    else if (pos == 1)
    {
        *str++ = '(';
        while (*p != '\0')
        {
            *str++ = *p++;
        }
        *str++ = ')';
    }
    else
    {

        while (*p != '\0')
        {
            *str++ = *p++;
        }
        *str++ = '(';
        *str++ = ')';
    }

    *str = '\0';
    return h;
}

typedef struct list
{
    char *val;
    struct list *next;
} list_t;

list_t *listAdd(list_t *head, char *c)
{
    if (head == NULL)
    {
        head = malloc(sizeof(list_t));
        head->val = c;
        head->next = NULL;
    }
    else
    {
        list_t *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = listAdd(NULL, c);
    }
    return head;
}

int listSize(list_t *head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        list_t *p = head;
        int len = 0;
        while (p != NULL)
        {
            p = p->next;
            len++;
        }
        return len;
    }
}
void listFree(list_t *head)
{
    if (head != NULL)
    {
        list_t *p = head;
        while (p != NULL)
        {
            list_t *q = p->next;
            free(p);
            p = q;
        }
    }
}

void listPrint(list_t *head)
{
    printf("list \n");
    if (head == NULL)
    {
        printf("\n");
    }
    else
    {
        list_t *p = head;
        while (p != NULL)
        {
            printf("%s ", p->val);
            p = p->next;
        }
        printf("\n");
    }
}

char **listToArr(list_t *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        int len = listSize(head);
        char **arr = malloc(sizeof(char *) * (len));
        int i = 0;
        list_t *p = head;
        while (p != NULL)
        {
            arr[i++] = p->val;
            p = p->next;
        }
        return arr;
    }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **generateParenthesis(int n, int *returnSize)
{
    if(map[n]){
        *returnSize = maplen[n];
        return map[n];
    }
    // int len = n * (n + 1) / 2;
    list_t *head = NULL;
    if (n == 0)
    {
        *returnSize = 1;
        char **arr = malloc(sizeof(char *));
        arr[0] = NULL;
        return arr;
    }
    else if (n == 1)
    {
        *returnSize = 1;
        char **arr = malloc(sizeof(char *));
        arr[0] = "()";
        return arr;
    }
    else
    {
        int j = 0;
        int parentLen = 0;
        int grandLen = 0;
        int dup = 0;

        for (int l = 0; l < n; l++)
        {
            char **parent = generateParenthesis(l, &parentLen);
            char **grand = generateParenthesis(n - 1 - l, &grandLen);
            for (int i = 0; i < parentLen; i++)
            {
                for (int j = 0; j < grandLen; j++)
                {
                    char *parentChar = parent[i];
                    if (!parentChar)
                    {
                        parentChar = "";
                    }
                    char *grandChar = grand[j];
                    if (!grandChar)
                    {
                        grandChar = "";
                    }
                    //printf("p %s g %s\n", parentChar, grandChar);
                    char *o = addChar(1, parentChar);
                    head = listAdd(head, catChar(o, grandChar));
                    free(o);
                }
            }
            //free(parent);
            //free(grand);
        }
    }
    int len = listSize(head);
    *returnSize = len;
    char **arr = listToArr(head);
    listFree(head);
    map[n] = arr;
    maplen[n] = len;
    return arr;
}

/*example start*/
// 回溯法求解
#define MAX_SIZE 1430  // 卡特兰数: 1, 1, 2, 5, 14, 42, 132, 429, 1430
void generate(int left, int right, int n, char *str, int index, char **result, int *returnSize) {
    if (index == 2 * n) { // 当前长度已达2n
        result[(*returnSize)] =  (char*)calloc((2 * n + 1), sizeof(char));
        strcpy(result[(*returnSize)++], str);
        return;
    }
    // 如果左括号数量不大于 n，可以放一个左括号
    if (left < n) {
        str[index] = '(';
        generate(left + 1, right, n, str, index + 1, result, returnSize);
    }
    // 如果右括号数量小于左括号的数量，可以放一个右括号
    if (right < left) {
        str[index] = ')';
        generate(left, right + 1, n, str, index + 1, result, returnSize);
    }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis1(int n, int *returnSize) {
    char *str = (char*)calloc((2 * n + 1), sizeof(char));
    char **result = (char **)malloc(sizeof(char *) * MAX_SIZE);
    *returnSize = 0;
    generate(0, 0, n, str, 0, result, returnSize);
    return result;
}
/*example end*/

int main()
{
    int returnSize = 0;
    int n = 8;
    char **arr = generateParenthesis(n, &returnSize);
    if (arr)
    {
        printf("n %d\n", n);
        for (int i = 0; i < returnSize; i++)
        {
            printf("%s ", arr[i]);
            if(i % 10 == 0){
                printf("\n");
            }
            free(arr[i]);
        }
        printf("\n");
        free(arr);
    }
    return EXIT_SUCCESS;
}