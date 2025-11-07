#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void prepend(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void deleteNode(int key) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {

            if (temp->prev == NULL) {
                head = temp->next;
                if (head != NULL)
                    head->prev = NULL;
                free(temp);
                return;
            }


            if (temp->next == NULL) {
                temp->prev->next = NULL;
                free(temp);
                return;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            return;
        }
        temp = temp->next;
    }
}

void displayForward() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}


void displayBackward(struct Node* node) {
    if (node == NULL)
        return;

    displayBackward(node->next);
    printf("%d", node->data);
    if (node->prev != NULL)
        printf(" <-> ");
}

int main() {
    prepend(10);
    append(20);
    append(30);
    prepend(5);

    printf("Forward Traversal:\n");
    displayForward();

    printf("Backward Traversal:\n");
    displayBackward(head);
    printf("\n");

    deleteNode(20);

    printf("After Deleting 20:\n");
    displayForward();

    return 0;
}
