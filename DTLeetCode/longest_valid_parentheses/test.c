#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int i;
    struct stack *next;
} stack_t;

stack_t *stackPush(stack_t *stack, int i)
{
    if (stack == NULL)
    {
        stack = malloc(sizeof(stack_t));
        stack->i = i;
        stack->next = NULL;
    }
    else
    {
        stack_t *p = stackPush(NULL, i);
        p->next = stack;
        stack = p;
    }
    return stack;
}

int stackPop(stack_t **stack)
{
    if (*stack == NULL)
    {
        return 0;
    }
    else
    {
        stack_t *p = *stack;
        *stack = (*stack)->next;
        int i = p->i;
        return i;
    }
}

void stackFree(stack_t *stack)
{
    if (stack != NULL)
    {
        stack_t *p = stack;
        while (p != NULL)
        {
            stack_t *q = p;
            p = p->next;
            free(q);
        }
    }
}

void testPtr(int *a)
{
    *a = 2;
}

int main()
{
    int i = 1;
    int *a = &i;
    testPtr(a);
    printf("a %d\n", *a);
    stack_t *s = stackPush(NULL, 'a');
    s = stackPush(s, 'b');
    s = stackPush(s, 'c');
    s = stackPush(s, 'd');
    s = stackPush(s, 'e');
    while (1)
    {
        char* cptr = stackPop(&s);
        if (cptr != NULL)
        {
            printf("%c ", *cptr);
            free(cptr);
        } else {
            break;
        }
    }
    stackFree(s);
    return 0;
}