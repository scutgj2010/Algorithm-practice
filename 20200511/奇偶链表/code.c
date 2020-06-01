/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    struct ListNode * newPtr; 
    struct ListNode * oddPtr;
    struct ListNode * evenPtr;
    struct ListNode * evenHeadPtr;
    if(head == NULL) {
        return head;
    } else if(head->next) {
        oddPtr = head;
        evenPtr = head->next;
    } else {
        return head;
    }
    
    newPtr = evenPtr->next;
    evenHeadPtr = evenPtr;
    while(newPtr && newPtr->next){
        oddPtr->next = newPtr;
        evenPtr->next = newPtr->next;
        oddPtr = oddPtr->next;
        evenPtr = evenPtr->next;
        newPtr = evenPtr->next;
    }

    if(newPtr) {
        oddPtr->next = newPtr;
        oddPtr = oddPtr->next;
    }
    evenPtr->next = NULL;
    oddPtr->next = evenHeadPtr;

    return head;
}