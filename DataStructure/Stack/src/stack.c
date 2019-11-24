#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack_t *createStack(unsigned int num)
{
    struct stack_t *stack = (struct stack_t *)malloc(sizeof(struct stack_t));
    stack->capacity = num;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    stack->top = -1;
    return stack;
}
void deleteStack(struct stack_t *stack)
{
    stack->capacity = 0;
    stack->top = -1;
    free(stack->array);
    free(stack);
}

int isFull(struct stack_t *stack)
{
    if (stack->top == (stack->capacity - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct stack_t *stack)
{
    if (stack->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack_t *stack, int data)
{
    if (isFull(stack))
    {
        printf("Stack is full\n");
    }
    else
    {
        stack->array[++stack->top] = data;
    }
}

int pop(struct stack_t *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return 0;
    }
    else
    {
        return stack->array[stack->top--];
    }
}

void peek(struct stack_t *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("current element:%d\n",stack->array[stack->top]);
    }
}

int main(int argc, char **argv)
{
    struct stack_t *stack = createStack(10);

    push(stack, 1);
    peek(stack);
    push(stack, 2);
    peek(stack);
    push(stack, 3);
    peek(stack);
    push(stack, 4);
    peek(stack);
    push(stack, 5);
    peek(stack);
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    peek(stack);
    deleteStack(stack);
    return 0;
}
