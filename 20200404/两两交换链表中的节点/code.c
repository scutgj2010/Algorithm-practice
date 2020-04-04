struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode * temp;
    if(head == NULL || head->next == NULL) {
        return head;
    }
    temp = swapPairs(head->next->next);
    head->next->next = head;
    head = head->next;
    head->next->next = temp;
    return head;    
}