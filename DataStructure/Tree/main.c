#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(int argc, char** argv){
	/*Code To Test the logic
	  Creating an example tree
	            5
			   / \
			  3   10
			 / \   \
			1   4   11
    */
    BstNode *root = NULL;    
	root = insertNode(root,5); 
    root = insertNode(root,10);
	root = insertNode(root,3); 
    root = insertNode(root,4); 
	root = insertNode(root,1); 
    root = insertNode(root,11);
    BstNode *root2 = NULL;    
	root2 = insertNode(root2,5); 
    root2 = insertNode(root2,10);
	root2 = insertNode(root2,3); 
    root2 = insertNode(root2,4); 
	root2 = insertNode(root2,1); 
    root2 = insertNode(root2,11);

	displayNode(root);
	printf("\n");
	displayNode(root2);
	printf("\n");
	if(isSame(root,root2)){
		printf("Two tree is the same\n");
	}else{
		printf("Two tree is different\n");
	}
	printf("\n");
	// Deleting node with value 5, change this value to test other cases
	//root = deleteNode(root,5);
	invertNode(root);
	//Print Nodes in Inorder
	displayNode(root);
	printf("\n");
    return 0;

}
