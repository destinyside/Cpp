#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copyChar(char *s)
{
    char *p = s;
    int len = strlen(p);
    char *str = malloc(sizeof(char) * (len + 1));
    char *h = str;
    for (int i = 0; i < len + 1; i++)
    {
        h[i] = 0;
    }
    while (p && *p != '\0')
    {
        *str++ = *p++;
    }
    h[len] = '\0';
    return h;
}

char *addChar(int pos, char *s)
{

    char *p = s;
    int len = strlen(p);
    char *str = malloc(sizeof(char) * (len + 3));
    char *h = str;
    if (pos == 0)
    {
        *str++ = '(';
        *str++ = ')';
        while (p && *p != '\0')
        {
            *str++ = *p++;
        }
    }
    else if (pos == 1)
    {
        *str++ = '(';
        while (p && *p != '\0')
        {
            *str++ = *p++;
        }
        *str++ = ')';
    }
    else
    {

        while (p && *p != '\0')
        {
            *str++ = *p++;
        }
        *str++ = '(';
        *str++ = ')';
    }
    *str = '\0';
    return h;
}

char *addChar1(int pos, char *s)
{

    char *p = s;
    int len = strlen(p);
    // char *str = malloc(sizeof(char) * (len + 3));
    char str[len + 3];
    char *h = str;
    int i = 0;
    if (pos == 0)
    {
        //*str++ = '(';
        //*str++ = ')';
        str[i++] = '(';
        str[i++] = ')';
        while (*p != '\0')
        {
            //*str++ = *p++;
            str[i++] = *p++;
        }
    }
    else if (pos == 1)
    {
        //*str++ = '(';
        str[i++] = '(';
        while (*p != '\0')
        {
            //*str++ = *p++;
            str[i++] = *p++;
        }
        //*str++ = ')';
        str[i++] = ')';
    }
    else
    {

        while (*p != '\0')
        {
            //*str++ = *p++;
            str[i++] = *p++;
        }
        //*str++ = '(';
        //*str++ = ')';
        str[i++] = '(';
        str[i++] = ')';
    }

    //*str = '\0';
    str[i] = '\0';
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
        char **arr = malloc(sizeof(char *) * (len + 1));
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

int main()
{
    char **arr = malloc(sizeof(char *) * 3);
    char *o = addChar(1, "()");
    printf("outer %s\n", o);
    arr[0] = o;
    char *l = addChar(0, "()");
    printf("left  %s\n", l);
    arr[1] = l;
    char *r = addChar(2, "()()()");
    printf("right %s\n", r);
    arr[2] = r;
    char **arr1 = malloc(sizeof(char *));
    arr1[0] = o;
    list_t *head = listAdd(NULL, o);
    head = listAdd(head, l);
    head = listAdd(head, r);
    char *m = copyChar(r);
    head = listAdd(head, m);
    listPrint(head);
    int len = listSize(head);
    char **arr2 = listToArr(head);
    listFree(head);
    for (int i = 0; i < len; i++)
    {
        printf("list to arr: %s\n", arr2[i]);
    }
    
    free(m);
    free(arr2);
    // free(o);

    free(l);
    free(r);
    free(arr);
    printf("outer1 %s\n", arr1[0]);
    free(arr1[0]);
    free(arr1);
    return 0;
}