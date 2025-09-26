#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

struct Node* constructTree(int pre[], int post[], int* preIndex, int l, int h, int size) {
    if (*preIndex >= size || l > h)
        return NULL;

    struct Node* root = newNode(pre[*preIndex]);
    (*preIndex)++;

    if (l == h || *preIndex >= size)
        return root;

    int i = search(post, l, h, pre[*preIndex]);

    if (i <= h) {
        root->left = constructTree(pre, post, preIndex, l, i, size);
        root->right = constructTree(pre, post, preIndex, i + 1, h - 1, size);
    }

    return root;
}

void printInorder(struct Node* root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    int pre[]  = {1, 2, 4, 5, 3, 6, 7};
    int post[] = {4, 5, 2, 6, 7, 3, 1};
    int size = sizeof(pre) / sizeof(pre[0]);

    int preIndex = 0;
    struct Node* root = constructTree(pre, post, &preIndex, 0, size - 1, size);

    printf("Inorder Traversal of constructed tree:\n");
    printInorder(root);

    return 0;
}