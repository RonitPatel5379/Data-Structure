#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* insertfront(struct node* head,int data){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

struct node* insertEnd(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        return newNode;
    }
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct node* deletefront(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    } 
    return head;
}

struct node* deleteend(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        printf("Last node deleted.\n");
    }
    return head;
}

struct node* deleteposition(struct node* head,int pos) {
   if (head == NULL) {
        printf("List is empty.\n");
    } else if (pos == 1) {
        deletefront(head);
    } else {
        struct node* temp = head;
        for (int i = 1; i < pos - 1 ; i++) {
            if( temp != NULL){
                temp = temp->next;
        }
    }
        if (temp == NULL || temp->next == NULL) {
            printf("Invalid position.\n");
        } else {
            struct node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            free(nodeToDelete);
            printf("Node at position %d deleted.\n", pos);
        }
    }
    return head;
}

struct node* countnodes(struct node* head) {
    int count = 0;
    struct node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Number of nodes: %d\n", count);
    return head;
}

struct node* isCompare(struct node* head1, struct node* head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->data != head2->data)
        return 0;
        head1 = head1->next;
        head2 = head2->next;
    }
    return (head1 == NULL && head2 == NULL);
}

void display(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void main() {
    int data;
    int choice,pos;
    struct node* head = NULL;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete front node\n");
        printf("4. Delete end node\n");
        printf("5. Delete node at position\n");
        printf("6. Display list\n");
        printf("7. Compare list\n");
        printf("8. Count nodes\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &data);
            insertfront(head,data);
        } else if (choice == 2) {
            printf("Enter value: ");
            scanf("%d", &data);
            insertEnd(head,data);
        } else if (choice == 3) {
            deletefront(head);
        } else if (choice == 4) {
            deleteend(head);
        } else if (choice == 5) {
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteposition(head,pos);
        } else if (choice == 6) {
            display(head);
        } else if (choice == 7) {
            countnodes(head);
        } else if (choice == 8) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    struct node* list1 = NULL;
    struct node* list2 = NULL;
    int n1, n2, i, val;

    printf("Enter number of nodes in List 1: ");
    scanf("%d", &n1);
    printf("Enter values for List 1:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d", &val);
        list1 = insertEnd(list1, val);
    }

    printf("Enter number of nodes in List 2: ");
    scanf("%d", &n2);
    printf("Enter values for List 2:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d", &val);
        list2 = insertEnd(list2, val);
    }

    printf("List 1: ");
    display(list1);
    printf("List 2: ");
    display(list2);

    if (isCompare(list1, list2)) {
        printf("Both linked lists are identical.\n");
    } else {
        printf("Linked lists are not identical.\n");
    }
}