struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
        struct ListNode * temp;
        struct ListNode * next;
        struct ListNode * pre;
    
        if((0 == n)|| (NULL == head))
        {
            return head;
        }
    
        if(NULL == head->next)
        {
            return head->next;
        }
    
        int num = 1;
        next = head;
        temp = head;
        while(next->next)
        {
           num++;
           pre = next;
           next = next->next;
           if(num > n)
           {
               temp = temp->next;
           }
        }
    
        if(num == n)
        {
            return head->next;
        }
        else
        {
            if(1 == n)
            {
                pre->next = NULL;
            }
            else
            {
                temp->val = temp->next->val;
                temp->next = temp->next->next;
            }
            return head;
        }
}