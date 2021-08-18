/* Implementing stack using queues
 * @Harshit Sharma, 1910990073
 * Assignment-4(Stacks and Queues)
*/ 

typedef struct {
    int *q1;
    int *q2;
    int front1;
    int rear1;
    int front2;
    int rear2;
    int top;
} MyStack;

// Initialize your DS.

MyStack* myStackCreate() {
    MyStack *obj = malloc(sizeof(MyStack));
    obj -> q1 = malloc(101 * sizeof(int));
    obj -> q2 = malloc(101 * sizeof(int));
    obj -> rear1 = -1;
    obj -> front1 = -1;
    obj -> rear2 = -1;
    obj -> front2 = -1;
    return obj;
}

// Push element x onto stack

void myStackPush(MyStack* obj, int x) {
    obj -> top = x; 
    (obj -> front1)++;
    obj -> q1[ obj -> front1 ] = x;
}

// Removes the element on top of the stack and returns that element.

int myStackPop(MyStack* obj) {
    int x;
    
    if(obj -> front2 == -1){
         
       obj -> rear2 = obj -> front1;
       while(obj -> rear1 < obj -> front1)
       {
            (obj -> front2)++;
            (obj -> rear1)++;
            obj -> q2[obj -> front2] = obj->q1[obj -> rear1];
       }
        obj -> front1 = -1;
        obj -> rear1 = -1;
    }
    if(obj -> rear2 <= obj -> front2)
    {    
        x  = obj -> q2[obj -> rear2];
        (obj -> rear2)--;
    }
    if(obj -> rear2 < 0)
    {
        obj -> rear2 = -1; 
        obj -> front2 = -1;
    }
        
    return x;
}

// Get the top element of stack

int myStackTop(MyStack* obj) {
    if( obj -> front2 == -1 ){
        return obj->top;   
    }
    
    return obj -> q2[obj -> rear2];
}

// returns whether the stack is empty

bool myStackEmpty(MyStack* obj) {
    if(obj -> front1 == -1 && obj -> front2 == -1)
        return 1;
    
    return 0;
}

void myStackFree(MyStack* obj) {
    free(obj -> q1);
    free(obj -> q2);
    free(obj);
}


