#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL)
        return newNode;
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* insertAtPosition(struct Node* head, int value, int position) {
    if (position == 1)
        return insertAtBeginning(head, value);

    struct Node* newNode = createNode(value);
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range!\n");
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (position == 1)
        return deleteAtBeginning(head);

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range!\n");
        return head;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    return head;
}

void search(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found in the list.\n", key);
}

int main() {
    struct Node* head = NULL;
    int choice, value, position;

    while (1) {
        printf("\n----- Singly Linked List Menu -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Position (Middle)\n");
        printf("3. Insert at End\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at Position (Middle)\n");
        printf("6. Delete at End\n");
        printf("7. Search Element\n");
        printf("8. Traverse\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            head = insertAtBeginning(head, value);
            break;

        case 2:
            printf("Enter value and position: ");
            scanf("%d %d", &value, &position);
            head = insertAtPosition(head, value, position);
            break;

        case 3:
            printf("Enter value: ");
            scanf("%d", &value);
            head = insertAtEnd(head, value);
            break;

        case 4:
            head = deleteAtBeginning(head);
            break;

        case 5:
            printf("Enter position: ");
            scanf("%d", &position);
            head = deleteAtPosition(head, position);
            break;

        case 6:
            head = deleteAtEnd(head);
            break;

        case 7:
            printf("Enter element to search: ");
            scanf("%d", &value);
            search(head, value);
            break;

        case 8:
            traverse(head);
            break;

        case 9:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
