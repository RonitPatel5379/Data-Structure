#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

struct Node* insert(struct Node* root,int data) {
  if (root == NULL)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

int isSymmetric(struct Node* left, struct Node* right) {
    if (left == NULL && right == NULL)
        return -1;
    if (left == NULL || right == NULL)
        return 1;
    if (left->data != right->data)
        return 0;
    return isSymmetric(left->left, right->right) &&
           isSymmetric(left->right, right->left);
}

void main() {
  struct Node* root = NULL;
  root = insert(root,8);
  root->left = insert(root->left,5);
  root->right = insert(root->right,7);
  root->left->left = insert(root->left->left,3);
  root->left->right = insert(root->left->right,6);
  root->right->left = insert(root->right->left,6);
  root->right->right = insert(root->right->right,3);

  if(isSymmetric(root->left,root->right)) {
    printf("Tree is symmetric");
  }
  else {
    printf("Tree is NOT symmetric");
  }
}