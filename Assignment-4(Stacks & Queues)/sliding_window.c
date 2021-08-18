/*
 * Program Code: Sliding Window Maximum on LeetCode
 * @author Harshit Sharma, 1910990073
 * @date 18/07/2021
*/

int *deque;
int front = -1, rear = -1;
int size;

int is_empty()
{
    if(front == -1)
        return 1;
    else
        return 0;
}

int is_full()
{
     if((front == 0 && rear == size - 1) || front == rear + 1)
         return 1;
     else
         return 0;
}

void push_front(int value)
{
    if(is_full())
    {
        return -1;
    }
    
    if (is_empty())
    {
        front = 0;
        rear = 0;
    }
    else
        front = front - 1;

    if (front < 0)
        front = size - 1;

    deque[front] = value;
    
}

void push_back(int value)
{
    if(is_full())
    {
        return -1;
    }
    
    if (is_empty())
    {
        front = 0;
        rear = 0;
    }
    else
        rear = (rear + 1) % size;

    deque[rear] = value;
}

int pop_front()
{
    //if deque is empty
    
    if(is_empty())
      return -1;

    int temp = deque[front];

    //empty the deque

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }

    return temp;
}

int pop_back()
{
    //if deque is empty

    if(is_empty())
       return -1;

    int temp = deque[rear];

    //empty the deque

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        rear--;
    }
    if (rear < 0)
        rear = size - 1;

    return temp;
}

int Front()
{
    return deque[front];
}

int back()
{
    return deque[rear];
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    size = k;
    front = rear = -1;
    deque = (int *)malloc(sizeof(int) * k);
    int *ans = (int *)malloc(sizeof(int) * (numsSize - k + 1));
    *returnSize = numsSize - k + 1;

    for (int i = 0; i < numsSize; i++)
    {
        
        while (!is_empty() && Front() <= (i - k))
            pop_front();

        //popping out elements that are smaller
        
	while (!is_empty() && nums[i] >= nums[back()])
            pop_back();

        push_back(i);

        if (i >= (k - 1))
            ans[i - (k - 1)] = nums[Front()];
    }

    return ans;
}
