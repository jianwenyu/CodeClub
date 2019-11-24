#include <stdio.h>
#include "linklist.h"

int main(int argc, char **argv)
{

    struct node_t *head = NULL;

    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    printf("There are %d elements in the link list\n", countNum(&head));
    display(&head);
    dequeue(&head);
    printf("There are %d elements in the link list\n", countNum(&head));
    display(&head);
    dequeue(&head);
    printf("There are %d elements in the link list\n", countNum(&head));
    display(&head);
    deleteList(&head);
    printf("There are %d elements in the link list\n", countNum(&head));
    display(&head);
    return 0;
}