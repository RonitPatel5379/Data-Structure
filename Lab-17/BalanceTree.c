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
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int checkHeight(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1;

    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1;

    if ((leftHeight - rightHeight) > 1)
        return -1;

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int isBalanced(struct Node* root) {
    return checkHeight(root) != -1;
}

void main() {
    struct Node* root1 = createNode(3);
    root1->left = createNode(9);
    root1->right = createNode(20);
    root1->right->left = createNode(15);
    root1->right->right = createNode(7);

    if (isBalanced(root1))
        printf("TRUE\n");
    else
        printf("FALSE\n");

    struct Node* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(2);
    root2->left->left = createNode(3);
    root2->left->right = createNode(3);
    root2->left->left->left = createNode(4);
    root2->left->left->right = createNode(4);

    if (isBalanced(root2))
        printf("TRUE\n");
    else
        printf("FALSE\n");
}