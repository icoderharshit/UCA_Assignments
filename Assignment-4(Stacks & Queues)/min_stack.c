/*
 * Program - Min Stack from LeetCode
 * @author Harshit Sharma, 1910990073
*/

long long int minElement = -1 ;

typedef struct {
    int top;
    long long int arr[10000];
} MinStack;

// initialise DS

MinStack* minStackCreate() {
    static MinStack stack;
    stack.top = -1;
    return &stack;
}

void minStackPush(MinStack* obj, long long int val) {
    if(obj->top == -1)
    {
        obj->top++;
        obj->arr[obj->top] = val;
        minElement = val;
    }
    else
    {
        if(val >= minElement)
        {
            obj->top++;
            obj->arr[obj->top] = val;
        }
        else if(val < minElement)
        {
            obj->top++;
            obj->arr[obj->top] = 2*val - minElement;
            minElement = val;
        }
            
    }
}

void minStackPop(MinStack* obj) {
    long long int y;
    if(obj->arr[obj->top] >= minEle)
    {
        y = obj->arr[obj->top];
        obj->top--;
    }
    else if(obj->arr[obj->top] < minEle)
    {
        y = minEle;
        minEle = 2*minEle - obj->arr[obj->top];
        obj->top--;
    
    }
        
}

int minStackTop(MinStack* obj) {
    if(obj->arr[obj->top] >= minEle)
    {
        return obj->arr[obj->top];
    }
    else 
    {
        return minEle;
    }
}


int minStackGetMin(MinStack* obj) {
    return minEle;
}

void minStackFree(MinStack* obj) {
    obj->top = -1;
}

