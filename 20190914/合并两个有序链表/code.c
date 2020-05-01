/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode * prehead = malloc(sizeof(struct ListNode));
    struct ListNode *prev = prehead;
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            prev->next = l1;
            l1 = l1->next;
        } else {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
   }

   prev->next = l1 == NULL ? l2 : l1;

   return prehead->next;
}