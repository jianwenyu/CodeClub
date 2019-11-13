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
    if (root != NULL){
        while (root->left != NULL){
            root = root->left; // smaller value is always on the left side
        }
        return root;
    }
    else{
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
        printf("find it:%d\n",data);
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
            printf("dot map is coming\n");
            struct BstNode *temp = findMin(root->right);
            printf("dot map is coming2\n");
            printf("%d\n", temp->data);
            root->data = temp->data;
            printf("dot map is coming3\n");
            root->right = deleteNode(root->right, data);
            printf("dot map is coming4\n");
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
    else if (data <= root->data )
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

/* Given a binary search tree and a data, this function deletes the data 
   and returns the new root */
struct BstNode* deleteNode2(struct BstNode* root, int data) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the data to be deleted is smaller than the root's data, 
    // then it lies in left subtree 
    if (data < root->data) 
        root->left = deleteNode2(root->left, data); 
  
    // If the data to be deleted is greater than the root's data, 
    // then it lies in right subtree 
    else if (data > root->data) 
        root->right = deleteNode2(root->right, data); 
  
    // if data is same as root's data, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct BstNode *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct BstNode *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct BstNode* temp = findMin(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->data = temp->data; 
  
        // Delete the inorder successor 
        root->right = deleteNode2(root->right, temp->data); 
    } 
    return root; 
}