/*
* Resource: Leetcode Question No 234. , Tag-Easy
* Harshit Sharma 1910990073, 26 August 2021
* Assignment_6 - Linked List
*/

/** Given on Leetcode Q.234
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
*/

// creating a function to find middle of the given linked list.

struct ListNode* findMiddle(struct ListNode* head) {
    if(head->next == NULL) {
        return head;
    }
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

// creating a function to reverse the given linked list

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* next = NULL;
    
    while(head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    
    return prev;
}

// creating the required function to check if the given linked list is palindrome or not


int isPalindrome(struct ListNode* head){
    if(head->next == NULL) {
        return 1;
    }
    
    struct ListNode* midOfList = findMiddle(head);
    struct ListNode* head2 = midOfList->next;
    midOfList->next = NULL;
    
    head2 = reverseList(head2);
    
    while(head != NULL && head2 != NULL) {
        if(head->val != head2->val) {
            return 0;
        }
        
        head = head->next;
        head2 = head2->next;
    }
    
    return 1;
}


