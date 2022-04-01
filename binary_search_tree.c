#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

TreeNode *makeTreeNode(int value) {
    TreeNode* newNodePtr = NULL;
    newNodePtr = (TreeNode*)malloc(sizeof(TreeNode));
    newNodePtr->key = value;
    newNodePtr->left = NULL;
    newNodePtr->right = NULL;

    return newNodePtr;
}

TreeNode* insert(TreeNode* nodePtr, int item) {
    if(nodePtr == NULL) {
        nodePtr = makeTreeNode(item);
    } else if (item < nodePtr-> key) {
        nodePtr->left = insert(nodePtr->left,item);
    } else if(item > nodePtr-> key) {
        nodePtr->right = insert(nodePtr->right,item);
    }

    return nodePtr;
}

TreeNode* search(TreeNode* nodePtr,int target) {
    if(nodePtr != NULL) {
        if( target < nodePtr->key) {
            nodePtr = search(nodePtr->left,target);
        } else if( target > nodePtr->key) {
            nodePtr = search(nodePtr->right,target);
        }
    }

    return nodePtr;
}

void PreOrder(TreeNode* root){
    if(root != NULL)
    {
        printf("%d ", root->key);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}


int main() {
    TreeNode* root = NULL;
    root = insert(root,5);
    root = insert(root,7);
    root = insert(root,3);
    root = insert(root,2);
    root = insert(root,9);
    root = insert(root,8);
    root = insert(root,14);
    root = insert(root,20);
    root = insert(root,0);
    root = insert(root,-1);
    printf("---tim phan tu co gia tri bang 3-----\n");
    if(search(root,3) != NULL) {
        printf("tim thay !!\n");
    } else {
        printf("khong tim thay\n");
    }

    printf("duyet cac gia tri: \n");
    PreOrder(root);
    return 0;
}