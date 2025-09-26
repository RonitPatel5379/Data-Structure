#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    char phone[20];
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(char *name, char *phone) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, char *name, char *phone) {
    if (root == NULL) {
        return createNode(name, phone);
    }
    if (strcmp(name, root->name) < 0) {
        root->left = insert(root->left, name, phone);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insert(root->right, name, phone);
    } else {
        printf("Name already exists in Phonebook!\n");
    }
    return root;
}

struct Node* search(struct Node* root, char *name) {
    if (root == NULL || strcmp(root->name, name) == 0)
        return root;

    if (strcmp(name, root->name) < 0)
        return search(root->left, name);
    else
        return search(root->right, name);
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node* deleteNode(struct Node* root, char *name) {
    if (root == NULL) return root;

    if (strcmp(name, root->name) < 0) {
        root->left = deleteNode(root->left, name);
    } else if (strcmp(name, root->name) > 0) {
        root->right = deleteNode(root->right, name);
    } else {
    
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);
        strcpy(root->name, temp->name);
        strcpy(root->phone, temp->phone);
        root->right = deleteNode(root->right, temp->name);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("Name: %s | Phone: %s\n", root->name, root->phone);
        inorder(root->right);
    }
}

void reverseInorder(struct Node* root) {
    if (root != NULL) {
        reverseInorder(root->right);
        printf("Name: %s | Phone: %s\n", root->name, root->phone);
        reverseInorder(root->left);
    }
}

int main() {
    struct Node* root = NULL;
    int choice;
    char name[50], phone[20];

    while (1) {
        printf("\n--- PHONE BOOK MENU ---\n");
        printf("1. Add New Entry\n");
        printf("2. Remove Entry\n");
        printf("3. Search Phone Number\n");
        printf("4. List Entries (Ascending Order)\n");
        printf("5. List Entries (Descending Order)\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Enter Phone: ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = 0; 
                root = insert(root, name, phone);
                break;

            case 2:
                printf("Enter Name to Delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                root = deleteNode(root, name);
                break;

            case 3:
                printf("Enter Name to Search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                {
                    struct Node* result = search(root, name);
                    if (result != NULL)
                        printf("Phone Number of %s: %s\n", result->name, result->phone);
                    else
                        printf("Entry Not Found!\n");
                }
                break;

            case 4:
                printf("\nPhone Book (Ascending Order):\n");
                inorder(root);
                break;

            case 5:
                printf("\nPhone Book (Descending Order):\n");
                reverseInorder(root);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }
}