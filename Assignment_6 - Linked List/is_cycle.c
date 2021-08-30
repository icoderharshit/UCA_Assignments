/*
* Run test cases on Leetcode Q.No 142.
* Harshit Sharma 1910990073, 29 August 2021
* Assignment_6 - Linked List
*/


/** Given already in editor on Leetcode q.142
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// creating a function to return the node where the cycle begins and if not found, it will return NULL

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) {
            slow = head;
            
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            
            return slow;
        }
    }
    
    return NULL;
}

