#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// create queue
struct queue_t *createQueue(int size)
{
    struct queue_t *queue = (struct queue_t *)malloc(sizeof(struct queue_t));
    queue->front = 0;
    queue->rear = -1;
    queue->n = 0;
    queue->size = size;
    queue->array = (int *)malloc(size * sizeof(int));
}

// delete queue
void deleteQueue(struct queue_t *queue)
{
    free(queue->array);
    free(queue);
}

// check full
int isFull(struct queue_t *queue)
{
    if (queue != NULL)
    {
        return  queue->n == queue->size;
    }
    else
    {
        printf("Queue ptr is NULL\n");
        return 0;
    }
}

// check empty
int isEmpty(struct queue_t *queue)
{
    if (queue != NULL)
    {
        return queue->rear == queue->front;
    }
    else
    {
        printf("Queue ptr is NULL\n");
        return 0;
    }
}

// enqueue
void enqueue(struct queue_t *queue, int data)
{
    if (isFull)
    {
        pritnf("Queue is full\n");
    }
    else
    {
        queue->array[(++queue->rear)%queue->size] = data;
    }
}
// dequeue
int dequeue(struct queue_t *queue, int data)
{
    if (isEmpty)
    {
        pritnf("Queue is empty\n");
    }
    else
    {

        return queue->array[queue->front++];
    }
}
// count element
int countQueue(struct queue_t *queue, int data)
{
    if (queue != NULL)
    {

    }
    else
    {
        printf("Queue ptr is NULL\n");
        return 0;
    }
}

// display element in queue
void display(struct queue_t *queue){
    int i= queue->front;
    for(;i<=queue->rear;i++){

    }

}