/* Task description:
Building a tree

The program below builds a sorted binary tree. 
Each node holds an integer value. 
This tree can be used to test your solutions today. 
The tree is shown on the Homepage.

Functions you need to write:
->TraverseWrite a function that traverses the tree in order (left-root-right), and prints the values. 
  You should see the numbers in growing order.
  Hint: What can be really printed using printf? Just the value stored here. 
  How can then the other values be printed? Recursion is the answer.
->Delete: Write a function to destroy the tree, and call it when necessary from main() to prevent memory leak. 
  This function is recursive, as well.
  Hint: Inorder traversing will fail here. Both the left and right subtrees must be destroyed before destroying the root node.
->Numberofnodes: Write a function that counts and returns the number of nodes in the tree. Check the result.
->Sumofnodes: Write a function that returns the sum of the stored values. Check the result.
->Search_element: Write a function that finds a specific value in the tree and returns a pointer to the found node! 
  Returns NULL, if the value can not be found.
  Hint: 
    >There are no values in an empty tree.
    >If the value is in the root node then we have found it.
    >If the value in the root node is greater, search in the left subtree.
    >Otherwise try to find in the right subtree. 
->Negatetree: Write a function that negates (multiplies by –1) each value in a tree. 
  >Try to use the previous search function to locate elements in the negated tree (like –14). 
  What happens? Why? How to modify the search function to handle the negated tree? (Print the tree, and/or draw the negated tree, it helps a lot.)
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct BTree {
    int value;
    struct BTree *left, *right;
} BTree;

BTree *insert(BTree *root, int value) {
    if (root == NULL) {
        BTree *new_node = (BTree*) malloc(sizeof(BTree));
        new_node->value = value;
        new_node->left = new_node->right = NULL;
        return new_node;
    }
    if (value < root->value) {        /* insert left */
        root->left = insert(root->left, value);
    }
    else if (value > root->value) {   /* insert right */
        root->right = insert(root->right, value);
    }
    else {
        /* already in the tree */
    }
    return root;
}

void inorder(BTree *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

void deleteTree(BTree *root){

}

int main(void) {
    int sample[] = {15, 96, 34, 12, 14, 56, 21, 11, 10, 9, 78, 43, 0};
    BTree *root = NULL;
    int i;
    for (i = 0; sample[i] > 0; i++)
        root = insert(root, sample[i]);

    /* Call your functions here! */
    //printing
    inorder(root);
    printf("\n");



    return 0;
}
