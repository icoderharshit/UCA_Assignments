/*
 * Program to implement the Queue in C.
 * Harshit Sharma 1910990073, 5 August 2021 
 * Day_2_Coding_Assignment
*/

#include<stdio.h>
#include<stdlib.h>

//global variables for implementing the queue with the standard names according to the convention already being followed
int* queue = NULL;
int head = -1;
int tail = -1;
int queue_size = 0;
int count = 0;

// function for checking if the queue is empty or not
int is_empty() {
    if(head == -1) {
        return 1;
    }
        return 0;
}

// function for checking if the queue is fully filled or not
int is_full() {
    if(count == queue_size) {
        return 1;
    }
        return 0;
}

// function for insertion of an element in the queue
void enqueue(int num) {
    if(is_full() == 1) {
        printf("\nQueue is full\n");
        return;
    }
    if(is_empty() == 1) {
        head++;
    }
    tail = (tail + 1) % queue_size;
    queue[tail] = num;
    count++;
}

// function to pop head element from the queue
int dequeue() {
    if(is_empty() == 1) {
        printf("\nQueue is Empty\n");
        return -1;
    }
    int removed = queue[head];
    head = (head + 1) % queue_size;
    count--;

    if(count == 0) {
        head = tail = -1;
    }
    return removed;
}

// function to return head/top element in the queue
int peek() {
    if(is_empty() == 1) {
        printf("\nQueue is Empty\n");
        return -1;
    }
    return queue[head];
}

// function to print all the elements in the queue
void print() {
    if(is_empty() == 1) {
        printf("\nQueue is Empty\n");
        return;
    }

    int j = 0;
    for(int i = head; j++ < count; i = (i + 1) % queue_size ) {
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main() {

    printf("Enter the size of Queue:\n");
    scanf("%d",&queue_size);

    queue = (int*) calloc(queue_size, sizeof(int));
// loop for asking the user to enter an option until exit operation is called i.e. Option 6
    while(1) {
        int option = 0;
        int num = 0;

        printf("\nChoose one of the below given options: \n1. Insert Element\n2. Remove element\n3. Peek Element\n4. Call Empty() function\n5. Display Queue\n6. Exit\n");
        scanf("%d",&option);
        switch(option) {
            case 1:
                printf("\nEnter an element to be inserted: \n");
                scanf("%d",&num);
                enqueue(num);
                break;
            case 2:
                printf("\nThe element removed from the queue is %d\n",dequeue());
                break;
            case 3:
                printf("\nThe element present at head of Queue is %d\n", peek());
                break;
            case 4:
                if(is_empty()) {
                    printf("\nQueue is Empty\n");
                } else {
                    printf("\nQueue is not empty\n");
                }
                break;
            case 5:
                print();
                break;
            case 6:
                printf("Terminating the program...");
                exit(1);
            default:
                printf("Invalid operation\n");
        }
    }

            return 1;
}