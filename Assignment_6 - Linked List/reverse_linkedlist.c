/*
* Run test cases on Leetcode Q.No 92.
* Harshit Sharma 1910990073, 28 August 2021
* Assignment_6 - Linked List
*/

/** Given already in editor on Leetcode
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// creating a function to reverse the list between nodes left and right and returns the required head element.

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode* dummy = (struct ListNode*) malloc(sizeof(struct ListNode));
    dummy->next = head;
            
    struct ListNode* prevLeft = NULL;
    struct ListNode* curLeft = dummy;
    for(int i = 0; i < left; i++) {
        prevLeft = curLeft;
        curLeft = curLeft->next;
    }
    
    struct ListNode* prevRight = prevLeft;
    struct ListNode* curRight = curLeft;
    for(int i = left; i <= right; i++) {
        struct ListNode* next = curRight->next;
        curRight->next = prevRight;
        prevRight = curRight;
        curRight = next;
    }
    
    prevLeft->next = prevRight;
    curLeft->next = curRight;
    
    return dummy->next;
}

