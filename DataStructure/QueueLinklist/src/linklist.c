#include <stdlib.h>
#include <stdio.h>
#include "linklist.h"

// Create a node
struct node_t *createNode(int data)
{
    struct node_t *node = (struct node_t *)malloc(sizeof(struct node_t));
    node->data = data;
    node->next = NULL;
    printf("adding node-> %d\n", node->data);
    return node;
}

// appendNode at the end
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

// delete the node with specific data
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

// display element in the list
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

// count element in the list
int countNum(struct node_t **head)
{
    struct node_t *current = *head;
    int n = 0;
    while (current != 0)
    {
        n++;
        current = current->next;
    }
    return n;
}

// revert the list
void revertList(struct node_t **head)
{
    struct node_t *current = *head;
    struct node_t *previous = NULL;
    struct node_t *temp = NULL;
    while (current != NULL)
    {
        printf("revert:%d\n", current->data);
        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }
    *head = previous;
    printf("Revert finish\n");
}

// delete the lisk
void deleteList(struct node_t **head)
{
    struct node_t *temp = *head;
    while ((*head) != NULL)
    {
        temp = (*head);
        (*head) = (*head)->next;
        free(temp);
    }
}

// special for queue implementation
int dequeue(struct node_t **head)
{
    if (*head != NULL)
    {
        struct node_t *current = *head;
        *head = (*head)->next;
        int temp = current->data;
        free(current);
        return temp;
    }
    else
    {
        printf("The link list is empty\n");
    }
}