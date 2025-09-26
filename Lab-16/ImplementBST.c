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

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

struct Node* search(struct Node* root,int data) {
    if(root==NULL || root->data==data) 
      return root;
    if(data < root->data)
      return search(root->left,data);  
    return search(root->right,data);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\n\n---- Binary Search Tree Menu ----\n");
        printf("1. Insert a Node\n");
        printf("2. Delete a Node\n");
        printf("3. Search a Node\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Node inserted.\n");
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Node deleted (if it existed).\n");
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(root, data))
                    printf("Node found!\n");
                else
                    printf("Node not found.\n");
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

// #include<stdio.h>
// #include<stdlib.h>

// struct Node {
//     int data;
//     struct Node* left;
//     struct Node* right;
// };

// struct Node* createroot(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->left = newNode->right = NULL;
//     return newNode;
// }

// struct Node* insert(struct Node* root,int data) {
//     if(root==NULL) {
//         return createroot(data);
//     }
//     if(data < root->data) {
//         root->left = insert(root->left,data);
//     }
//     else if(data > root->data) {
//         root->right = insert(root->right,data);
//     }
//     return root;
// }

// struct Node* deleteNode(struct Node* root,int data) {
//     if(root==NULL) {
//         return root;
//     }
//     if(data < root->data) {
//         root->left = deleteNode(root->left,data);
//     }
//     else if(data > root->data)  {
//         root->right = deleteNode(root->right,data);
//     }
//     else {
//         if(root->left==NULL) {
//             struct Node* temp = root->right;
//             free(root);
//             return temp;
//         }
//         else if(root->right==NULL) {
//             struct Node* temp = root->left;
//             free(root);
//             return temp;
//         }
//         else {
//             struct Node* temp = root->right;
//             while(temp->left!=NULL) {
//                 temp = temp->left;
//             }
//             root->data = temp->data;
//             root->right = deleteNode(root->right,temp->data);
//         }
//     }
//     return root;
// }

// struct Node* search(struct Node* root,int data) {
//     if(root==NULL || root->data==data) {
//         return root;
//     }
//     else if(data < root->data) {
//         return search(root->left,data);
//     }
//     else {
//         return search(root->right,data);
//     }
// }

// void inorder(struct Node* root) {
//     if(root!=NULL) {
//         inorder(root->left);
//         printf("%d ",root->data);
//         inorder(root->right);
//     }
// }

// void preorder(struct Node* root) {
//     if(root!=NULL) {
//         printf("%d ",root->data);
//         preorder(root->left);
//         preorder(root->right);
//     }
// }

// void postorder(struct Node* root) {
//     if(root!=NULL) {
//         postorder(root->left);
//         postorder(root->right);
//         printf("%d ",root->data);
//     }
// }

// void main() {
//     struct Node* root= NULL;
//     int choice,data;
//     while(1) {
//         printf("\n\n----Binary search menu----\n");
//         printf("1. Insert a Node\n");
//         printf("2. Delete a Node\n");
//         printf("3. Search a Node\n");
//         printf("4. Inorder Traversal\n");
//         printf("5. Preorder Traversal\n");
//         printf("6. Postorder Traversal\n");
//         printf("7. Exit..\n");
//         printf("Enter the choice:");
//         scanf("%d",&choice);

//         switch(choice) {
//             case 1:
//             printf("Enter data to insert:");
//             scanf("%d",&data);
//             root = insert(root,data);
//             printf("Node is inserted.\n");
//             break;
//             case 2:
//             printf("Enter data to delete:");
//             scanf("%d",&data);
//             root = deleteNode(root,data);
//             printf("Node is deleted.\n");
//             break;
//             case 3:
//             printf("Enter data to search:");
//             scanf("%d",&data);
//             if(search(root,data)) {
//                 printf("Node is found.\n");
//             }
//             else {
//                 printf("Node is not found.\n");
//             }
//             break;
//             case 4:
//             printf("Inorder Traversal:");
//             inorder(root);
//             printf("\n");
//             break;
//             case 5:
//             printf("Preorder Traversal:");
//             preorder(root);
//             printf("\n");
//             break;
//             case 6:
//             printf("Postorder Traversal:");
//             postorder(root);
//             printf("\n");
//             break;
//             case 7:
//             printf("Exiting..\n");
//             exit(0);
//             break;
//             default:
//             printf("Invalid choice!");
//         }
//     }
// }