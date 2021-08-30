/*
* Program for implementing stack and its functions using Linked List.
* Harshit Sharma 1910990073, 24 August 2021
* Assignment_6 - Linked List
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;


Node* head = NULL;   // pointing to the last element of the stack
Node* tail = NULL;   // pointing to the top element of the stack

// push operation

void push(int val) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = val;
    node->next = NULL;
    node->prev = NULL;

    if(head == NULL && tail == NULL) {
        head = tail = node;
        return;
    }

    tail->next = node;
    node->prev = tail;
    tail = node;
}

// pop operation

int pop() {
    if(head == NULL && tail == NULL) {
        return -1;
    }

    int val = tail->value;
    if(head == tail) {
        head = tail = NULL;
        return val;
    }

    tail = tail->prev;
    head->next = NULL;

    return val;
}

// function to check if the stack is empty or not

int is_empty() {
    if(head == NULL && tail == NULL) {
        return 1;
    }
    
    return 0;
}

// returns the topmost element of the stack

int peek() {
    if(head == NULL && tail == NULL) {
        return -1;
    }

    int val = tail->value;
    return val;
}

int main() {
    while(1) {
        int option = 0;
        int number = 0;

        printf("\nWhich operation do you want to perform?\n");
        printf("1. Push element on the stack\n");
        printf("2. Pop element from the stack\n");
        printf("3. Get topmost element in the stack\n");
        printf("4. Chech if Stack is empty or not\n");
        printf("5. Exit\n\n");

        scanf("%d",&option);

        switch(option) {
            case 1:
                printf("\nEnter a number to be pushed :\n");
                scanf("%d", &number);
                push(number);
                break;
            case 2:
                printf("\nPopped element from the stack is %d\n", pop());
                break;
            case 3:
                printf("\nTopmost element in the stack is %d\n", peek());
                break;
            case 4:
                if(is_empty(number) == 1) {
                    printf("\nStack is empty !\n");
                } else {
                    printf("\n\nStack is not empty !\n\n");
                }
                break;
            case 5:
                exit(1);
        }
    }

    return 0;
}


