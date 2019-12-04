#include <stdio.h>
#include <stdlib.h>

/*
Reverse Linked List

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode
{
    int data;
    struct ListNode *next;
} list;

list *reverseList(list *head);
void print(list *sample);

int main(int argc, char **argv)
{
    int a[] = {1, 2, 3, 4, 5};
    list one, two, three, four, five;
    list *head;
    one.data = a[0];
    two.data = a[1];
    three.data = a[2];
    four.data = a[3];
    five.data = a[4];

    one.next = &two;
    two.next = &three;
    three.next = &four;
    four.next = &five;
    five.next = NULL;
    head = &one;
    
    while (head != NULL)
    {
        printf("%d \n", head->data);
        head = head->next;
    }

    head = reverseList(&one);

    while (head != NULL)
    {
        printf("%d \n", head->data);
        head = head->next;
    }
    //print(&two);
    return 0;
}

void print(list *sample)

{
    printf("%d \n", sample->data);
    return;
}

list *reverseList(list *head)
{
    list *q = NULL;
    list *r = NULL;

    while (head != NULL)
    {
        r = q;
        q = head;
        head = head->next;
        q->next = r;
    }

    head = q;
    return head;
}