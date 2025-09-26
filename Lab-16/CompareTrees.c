#include <stdio.h>
#include <stdlib.h>

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

int areSame(struct Node* root1, struct Node* root2) {
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 != NULL && root2 != NULL) {
        return (root1->data == root2->data) &&
               areSame(root1->left, root2->left) &&
               areSame(root1->right, root2->right);
    }
    return 0;
}

void main() {
    struct Node* root1 = NULL;
    struct Node* root2 = NULL;

    root1 = insert(root1,10);
    root1 = insert(root1,20);
    root1 = insert(root1,30);
    root1 = insert(root1,40);

    root2 = insert(root2,10);
    root2 = insert(root2,20);
    root2 = insert(root2,30);
    root2 = insert(root2,50);

    if (areSame(root1, root2))
        printf("The two trees are the same.\n");
    else
        printf("The two trees are NOT the same.\n");
}