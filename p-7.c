
#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL;

// Insert at the beginning
void insertBeginning(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (last == NULL) {
        last = newNode;
        newNode->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }

    printf("Node inserted at beginning.\n");
}

// Insert at the end
void insertEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (last == NULL) {
        last = newNode;
        newNode->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    printf("Node inserted at end.\n");
}

// Insert after a given node
void insertAfter(int key, int value) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = last->next;

    do {
        if (temp->data == key) {
            struct Node *newNode =
                (struct Node *)malloc(sizeof(struct Node));

            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;

            if (temp == last)
                last = newNode;

            printf("Node inserted after %d.\n", key);
            return;
        }

        temp = temp->next;
    } while (temp != last->next);

    printf("Node %d not found.\n", key);
}

// Delete the first node
void deleteFirst() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *first = last->next;

    if (first == last) {
        last = NULL;
    } else {
        last->next = first->next;
    }

    free(first);
    printf("First node deleted.\n");
}

// Delete the last node
void deleteLast() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = last->next;

    if (temp == last) {
        free(last);
        last = NULL;
    } else {
        while (temp->next != last)
            temp = temp->next;

        temp->next = last->next;
        free(last);
        last = temp;
    }

    printf("Last node deleted.\n");
}

// Delete node after a given node
void deleteAfter(int key) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = last->next;

    do {
        if (temp->data == key) {
            struct Node *del = temp->next;

            // If only one node exists
            if (del == temp) {
                printf("No node exists after %d.\n", key);
                return;
            }

            // If deleting the last node
            if (del == last)
                last = temp;

            temp->next = del->next;
            free(del);

            printf("Node after %d deleted.\n", key);
            return;
        }

        temp = temp->next;
    } while (temp != last->next);

    printf("Node %d not found.\n", key);
}

// Display all nodes
void display() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = last->next;

    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(back to first node)\n");
}

// Main function
int main() {
    int choice, value, key;

    while (1) {
        printf("\n--- Singly Circular Linked List ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a given node\n");
        printf("4. Delete first node\n");
        printf("5. Delete last node\n");
        printf("6. Delete node after a given node\n");
        printf("7. Display all nodes\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter the node after which to insert: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insertAfter(key, value);
                break;

            case 4:
                deleteFirst();
                break;

            case 5:
                deleteLast();
                break;

            case 6:
                printf("Enter the node after which to delete: ");
                scanf("%d", &key);
                deleteAfter(key);
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}