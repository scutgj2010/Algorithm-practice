/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode * quickIdx = head;
    struct ListNode * slowIdx = head;
    int counter = 0;
    while(quickIdx != NULL && quickIdx->next != NULL) {
        quickIdx = quickIdx->next->next;
        slowIdx = slowIdx->next;
        if(quickIdx == slowIdx) {
            goto start;
        }
    }
    return NULL;
start:
    while(head != slowIdx) {
        head = head->next;
        slowIdx = slowIdx->next; 
    }
    return head;
}