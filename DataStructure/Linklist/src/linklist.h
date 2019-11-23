#ifndef _LINKLIST_
#define _LINKLIST_

#define TRUE 1
#define FAULT 0

struct node_t
{
    int data;
    struct node_t *next;
};

struct node_t *createNode(int data);
void appendNode(struct node_t **head, int data);
int deleteNode(struct node_t **head, int data);
void display(struct node_t **head);
int countNum(struct node_t **head);
void revertList(struct node_t **head);
#endif