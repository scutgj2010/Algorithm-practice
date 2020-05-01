/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
    l1[0]->next = merge(l1[1:],l2)    l1[0]<l2[0]
    l2[0]->next = merge(l1,l2[1:])   otherwise
**/
?	
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL) {
        return l2;
    } else if(l2 == NULL) {
        return l1;
    } else if(l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next,l2);
        return l1;
    } else {
        l2->next =  mergeTwoLists(l1,l2->next);
        return l2;
    }
}

