/*
* Run test cases on Leetcode Q.No 61.
* Harshit Sharma 1910990073, 28 August 2021
* Assignment_6 - Linked List
*/

/** Given already on Leetcode
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// creating a function to return the required head of the list after rotating the given linked list by k times

struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head == NULL || head->next == NULL || k == 0) {
        return head;
    }
    
    struct ListNode* temp = head;
    int length = 1;
    
    while(temp->next != NULL) {
        length++;
        temp = temp->next;
    }
    
    temp->next = head;
    k %= length;
    k = length - k;
    while(k-- > 0) {
        temp = temp->next;
    }
    
    head = temp->next;
    temp->next = NULL;
    
    return head;
}

