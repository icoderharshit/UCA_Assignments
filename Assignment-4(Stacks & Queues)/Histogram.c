/*
 * Program for Largest Rectangle In Histogram 
 * Harshit Sharma 
 * Roll No : 1910990073
*/

int stack[10000];
int top = -1;
int is_empty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

void push(int item)
{
    if(top + 1 == 10000)
    {
        printf("Stack Overflow");
    }
    else
    {
        top++;
        stack[top] = item;
    }
}

int pop()
{
    int y;
    if(is_empty())
    {
        printf("Stack Underflow");
    }

    y = stack[top];
    top--;
    return y;
}

int peek()
{
    return stack[top];
}

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int largestRectangleArea(int* height, int heightSize){
    int result = 0;
    for (int i = 0; i <= heightSize; i++)
    {
        int x;
        if(i == heightSize)
        {
            x = 0;
        }
        else
        {
            x = height[i];
        }

        while (!is_empty() && height[peek()] >= x)
        {
            int curr = pop();
            int next_s = i - 1;
            int prev_s;
            if(is_empty())
            {
                prev_s = 0;
            }
            else
                prev_s = peek() + 1;
            int maxArea = height[curr] * (next_s - prev_s + 1);
            if (maxArea > result)
                result = maxArea;
        }
        if (i != heightSize)
            push(i);
    }
    return result;
}
