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

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node* findMax(struct Node* root) {
  while (root->right != NULL) {
        root = root->right;
  }
  return root;
}

void main() {
  struct Node* root = NULL;
  int data;
  root = insert(root,10);
  root = insert(root,3);
  root = insert(root,13);
  root = insert(root,2);
  root = insert(root,15);
  root = insert(root,5);
  root = insert(root,11);
  struct Node* minRoot = findMin(root);
  struct Node* maxRoot = findMax(root);
  printf("Smallest Elements:%d",minRoot->data);
  printf("\nLargest Elements:%d",maxRoot->data);
}