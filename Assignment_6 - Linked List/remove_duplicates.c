/*
* Run the test cases on Leetcode Q.No 82.
* Harshit Sharma 1910990073, 27 August 2021
* Assignment_6 - Linked List
*/

/** Given already in the editor on Leetcode
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// function that returns the list with nodes of values not containing any duplicates in the input list

struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    struct ListNode* resHead = (struct ListNode*) (malloc(sizeof(struct ListNode)));
    struct ListNode* temp = resHead;
    
    while(head != NULL && head->next != NULL) {
        if(head->val != head->next->val) {
            temp->next = head;
            temp = temp->next;
        } else {
            while(head->next != NULL && head->val == head->next->val) {
                head = head->next;
            }
        }
        
        head = head->next;
    }
    
    temp->next = head;
    return resHead->next;
}

