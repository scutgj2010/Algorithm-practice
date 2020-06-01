/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode *sentinel = malloc(sizeof(struct ListNode));
    sentinel->next = head;

    struct ListNode *curr = head, *prev = sentinel;
    
    while (curr != NULL){
        if (curr->val == val){
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        } else{
            prev = curr;
            curr = curr->next;
        }
    }
    head = sentinel->next;
    free(sentinel);
    return head;

}
