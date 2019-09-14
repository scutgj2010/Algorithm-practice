struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode * new = malloc(sizeof(struct ListNode));
    struct ListNode * temp ;
    struct ListNode * next = new;
    struct ListNode * l1next = l1;
    struct ListNode * l2next = l2;
    if(NULL == l1)
    {
        return l2;
    }
    if(NULL == l2)
    {
        return l1;
    }
    
    while(l1next || l2next)
    {
        temp = malloc(sizeof(struct ListNode));
        if((l1next)&&(l2next))
        {
            if(l1next->val > l2next->val)
            {                
                temp->val = l2next->val;  
                l2next = l2next->next;
            }
            else
            {
                temp->val = l1next->val;
                l1next = l1next->next;
            }          
        }
        else if(l1next)
        {
             temp->val = l1next->val;
             l1next = l1next->next;
        }
        else
        {
            temp->val = l2next->val;  
            l2next = l2next->next;
        }
        temp->next = NULL;
        next->next = temp;
        next = temp;  
    }
    return new->next;
}