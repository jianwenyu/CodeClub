#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

struct BstNode *getNewNode(int data)
{
    struct BstNode *root = (struct BstNode *)malloc(sizeof(struct BstNode));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

/* Find the minimum child */
struct BstNode *findMin(struct BstNode *root)
{
    if (root != NULL)
    {
        while (root->left != NULL)
        {
            root = root->left; // smaller value is always on the left side
        }
        return root;
    }
    else
    {
        return NULL;
    }
}

struct BstNode *deleteNode(struct BstNode *root, int data)
{
    if (root == NULL)
        return root; /* Empty node */
    else if (data < root->data)
        root->left = deleteNode(root->left, data); /* Search left */
    else if (data > root->data)
        root->right = deleteNode(root->right, data); /* Search right */
    /* found the node, there are 3 case */
    else
    {
        printf("find it:%d\n", data);
        // Case 1, No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
            return root;
        }
        // Case 2, one child
        else if (root->right == NULL)
        {
            struct BstNode *temp = root->left;
            free(root);
            return temp;
        }
        else if (root->left == NULL)
        {
            struct BstNode *temp = root->right;
            free(root);
            return temp;
        }
        // Case 3, two child
        else
        {
            struct BstNode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

struct BstNode *insertNode(struct BstNode *root, int data)
{
    if (root == NULL)
    {
        root = getNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}

unsigned int searchNode(struct BstNode *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->data == data)
    {
        return 1;
    }
    else if (data < root->data)
        return searchNode(root->left, data);

    else
    {
        return searchNode(root->right, data);
    }
}

void displayNode(struct BstNode *root)
{
    if (root != NULL)
    {
        displayNode(root->left);
        printf("%d ", root->data);
        displayNode(root->right);
    }
}
