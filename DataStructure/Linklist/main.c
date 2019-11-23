#include <stdio.h>
#include "linklist.h"

int main(int argc, char **argv)
{

    struct node_t *head = NULL;

    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);

    display(&head);
    deleteNode(&head, 2);
    display(&head);
    deleteNode(&head, 4);
    display(&head);

    return 0;
}