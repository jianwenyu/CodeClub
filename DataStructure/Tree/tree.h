#ifndef _H_BSTTREE_H_
#define _H_BSTTREE_H_

typedef struct BstNode
{
    /* data */
    int data;
    struct BstNode *left;
    struct BstNode *right;
} BstNode;

struct BstNode *getNewNode(int data);
struct BstNode *findMin(struct BstNode *root);
struct BstNode *deleteNode(struct BstNode *root, int data);
struct BstNode *deleteNode2(struct BstNode* root, int key);
struct BstNode *insertNode(struct BstNode *root, int data);
unsigned int searchNode(struct BstNode *root, int data);
void displayNode(struct BstNode *root);

#endif