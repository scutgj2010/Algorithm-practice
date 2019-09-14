bool hasCycle(struct ListNode *head) {
    struct ListNode * p1;
    struct ListNode * p2;
    
    if(NULL == head || NULL == head->next)
    {
        return false;
    }
    
    p1 = head->next;
    p2 = head->next->next;
    
    while((p1 != p2)&&(p1)&&(p2)&&(p2->next))
    {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    
    if((NULL == p1)||(NULL == p2)||(NULL == p2->next))
    {
        return false;
    }
    return true;
}