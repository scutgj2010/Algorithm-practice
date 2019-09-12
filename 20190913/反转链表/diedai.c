struct ListNode* reverseList(struct ListNode* head){
    
    struct ListNode* tail = malloc(sizeof(struct ListNode));
    struct ListNode* temp;
    struct ListNode* next;
    if(NULL == head)
    {
        return head;
    }
    tail->val = head->val;
    tail->next = NULL;
    next = head;
    while(next->next)
    {       
        next = next->next;
        temp = malloc(sizeof(struct ListNode));
        temp->val = next->val;
        temp->next = tail;
        tail = temp;
    }
    return tail;
}