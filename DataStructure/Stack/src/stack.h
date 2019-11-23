#ifndef H_STACK_H
#define H_STACK_H

struct stack_t
{
    int *array;
    int top;
    unsigned int capacity;
};

struct stack_t *createStack(unsigned int num);
void deleteStack(struct stack_t *stack);
int isFull(struct stack_t *stack);
int isEmpty(struct stack_t *stack);
void push(struct stack_t *stack, int data);
int pop(struct stack_t *stack);
#endif