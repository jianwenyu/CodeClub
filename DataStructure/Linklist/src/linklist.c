#include <stdlib.h>
#include <stdio.h>
#include "linklist.h"

struct node_t *createNode(int data)
{
    struct node_t *node = (struct node_t *)malloc(sizeof(struct node_t));
    node->data = data;
    node->next = NULL;
    printf("adding node-> %d\n", node->data);
    return node;
}

void appendNode(struct node_t **head, int data)
{
    if (*head == NULL)
    {

        *head = createNode(data);
        //printf("%d \n",(*head)->data);
    }
    else
    {
        struct node_t *current = *head;

        while (current->next != NULL)
        {
            //printf("%d \n",current->data);
            current = current->next;
        }
        current->next = createNode(data);
    }
}

int deleteNode(struct node_t **head, int data)
{
    struct node_t *current = *head;
    struct node_t *previous = NULL;
    while (current->next != NULL && current->data != data)
    {
        previous = current;
        current = current->next;
    }
    /* Found it in the middle of the link list*/
    if (current->data == data && current->next != NULL)
    {
        previous->next = current->next;
        free(current);
        return TRUE;
    }
    /* Found it in the end of the link list*/
    else if (current->data == data && current->next == NULL)
    {
        previous->next = NULL;
        free(current);
        return TRUE;
    }
    else
    {
        return FAULT;
    }
}

void display(struct node_t **head)
{
    if (*head != NULL)
    {
        struct node_t *current = *head;
        do
        {
            printf("%d ", current->data);
            current = current->next;
        } while (current != NULL);
        printf("\n");
    }
    else
    {
        printf("The link list is empty\n");
    }
}