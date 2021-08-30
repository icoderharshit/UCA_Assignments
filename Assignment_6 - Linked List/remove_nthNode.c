/* 
* Run Test cases on Leetcode Q.No 19.
* Harshit Sharma 1910990073, 27 August 2021
* Assignment_6 - Linked List
*/

/** Given in the editor already on Leetcode
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// function that returns the updated list after removing given nth node from the end of given list

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* temp = (struct ListNode*) malloc(sizeof(struct ListNode));
    temp->next = head;
    
    struct ListNode* slow = temp;
    struct ListNode* fast = temp;
    
    while(n-- > 0) {
        fast = fast->next;
    }
    
    if(fast->next == NULL) {
        return head->next;
    }
    
    while(fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    
    slow->next = slow->next->next;
    return head;
}

