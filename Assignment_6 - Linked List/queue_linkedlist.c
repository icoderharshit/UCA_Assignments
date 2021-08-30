/*
* Program for implementing queue and its functions using Linked List.
* Harshit Sharma 1910990073, 25 August 2021
* Assignment_6 - Linked List
*/

#include <stdio.h>
#include <stdlib.h>

// Implementing Queue and it's various operations and functions 

typedef struct Node {
    int value;
    struct Node* next;
} Node;


Node* head = NULL;   // pointing to the front of the queue.
Node* tail = NULL;   // pointing to the rear end of the queue.

// enqueue operation

void enqueue(int val) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = val;
    node->next = NULL;

    if(head == NULL && tail == NULL) {
        head = tail = node;
        return;
    }

    tail->next = node;
    tail = tail->next;
}

// dequeue operation

int dequeue() {
    if(head == NULL && tail == NULL) {
        return -1;
    }

    int val = head->value;
    if(head == tail) {
        head = tail = NULL;
        return val;
    }

    head = head->next;
    return val;
}

// check if queue is empty or not

int is_empty() {
    if(head == NULL && tail == NULL) {
        return 1;
    }
    
    return 0;
}

// get the peek element in front of the queue.

int peek() {
    if(head == NULL && tail == NULL) {
        return -1;
    }

    int val = head->value;
    return val;
}

int main() {
    while(1) {
        int option = 0;
        int number = 0;

        printf("\nWhich operation do you want to perform?\n");
        printf("1. Enqueue element in the queue.\n");
        printf("2. Dequeue element from the queue.\n");
        printf("3. Get Front element in the queue.\n");
        printf("4. Chech if Queue is empty or not.\n");
        printf("5. Exit\n\n");

        scanf("%d",&option);

        switch(option) {
            case 1:
                printf("\nEnter a number to be enqueued :\n");
                scanf("%d", &number);
                enqueue(number);
                break;
            case 2:
                printf("\nDequeued element from the queue is %d\n", dequeue());
                break;
            case 3:
                printf("\nFront element in the queue is %d\n", peek());
                break;
            case 4:
                if(is_empty(num) == 1) {
                    printf("\nQueue is empty.\n");
                } else {
                    printf("\n\nQueue is not empty.\n\n");
                }
                break;
            case 5:
                exit(1);
        }
    }

    return 0;
}


