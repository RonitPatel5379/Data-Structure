#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char Song[100];
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;
struct Node* temp1 = NULL;

struct Node* createNode(char Song[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->Song, Song);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addNode(char Song[]) {
    struct Node* Node = createNode(Song);
    if (head == NULL) {
        head = tail = Node;
        temp1 = Node;
    } else {
        tail->next = Node;
        Node->prev = tail;
        tail = Node;
    }
    printf("'%s' added to playlist.\n", Song);
}

void deleteNode(char Song[]) {
    struct Node* temp1 = head;
    while (temp1 != NULL) {
        if (strcmp(temp1->Song, Song) == 0) {
            if (temp1 == head) {
                head = temp1->next;
                if (head) head->prev = NULL;
            } else {
                temp1->prev->next = temp1->next;
            }
            if (temp1 == tail) {
                tail = temp1->prev;
                if (tail) tail->next = NULL;
            } else if (temp1->next) {
                temp1->next->prev = temp1->prev;
            }
            if (temp1 == temp1)
                temp1 = temp1->next ? temp1->next : temp1->prev;
            free(temp1);
            printf("'%s' deleted from playlist.\n", Song);
            return;
        }
        temp1 = temp1->next;
    }
    printf("Node '%s' not found in playlist.\n", Song);
}

void playtemp1() {
    if (temp1 == NULL)
        printf("No Node in playlist.\n");
    else
        printf("Playing: %s\n", temp1->Song);
}

void playNext() {
    if (temp1 != NULL && temp1->next != NULL) {
        temp1 = temp1->next;
        playtemp1();
    } else {
        printf("No next Node.\n");
    }
}

void playPrevious() {
    if (temp1 != NULL && temp1->prev != NULL) {
        temp1 = temp1->prev;
        playtemp1();
    } else {
        printf("No previous Node.\n");
    }
}

void displayPlaylist() {
    struct Node* temp1 = head;
    if (temp1 == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    printf("Playlist:\n");
    while (temp1 != NULL) {
        printf(" - %s", temp1->Song);
        if (temp1 == temp1) printf(" [temp1]");
        printf("\n");
        temp1 = temp1->next;
    }
}

void main() {
    int choice;
    char Song[100];

    while (1) {
        printf("\n--- Music Player ---\n");
        printf("1. Add Node\n");
        printf("2. Delete Node\n");
        printf("3. Play temp1 Node\n");
        printf("4. Play Next Node\n");
        printf("5. Play Previous Node\n");
        printf("6. Show Playlist\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter Song: ");
                fgets(Song, sizeof(Song), stdin);
                Song[strcspn(Song, "\n")] = '\0';
                addNode(Song);
                break;
            case 2:
                printf("Enter Song to delete: ");
                fgets(Song, sizeof(Song), stdin);
                Song[strcspn(Song, "\n")] = '\0';
                deleteNode(Song);
                break;
            case 3:
                playtemp1();
                break;
            case 4:
                playNext();
                break;
            case 5:
                playPrevious();
                break;
            case 6:
                displayPlaylist();
                break;
            case 7:
                printf("Exiting Music Player.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}