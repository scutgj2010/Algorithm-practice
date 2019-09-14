bool isPalindrome(struct ListNode* head){
       struct ListNode* p1 = head;
       struct ListNode* p2 = head;
       struct ListNode* p3 = NULL;
       
       int len = 1;
       if(NULL == head || NULL == head->next)
       {
           return true;
       }
       /*获取链表长度*/
       while(p1->next)
       {
           p1 = p1->next;
           len++;
       }
    
        /*将链表前半部转置*/
        for(int i = 0;i < (len / 2);i++)
        {
            p1= p2->next;
            p2->next = p3;
            p3 = p2;
            p2 = p1;
        }
    
        /*从链表中间朝两边遍历，如果不相同则不是回文链表*/
        if((len % 2) == 1)
            p1 = p1->next;
       
        while(p1 != NULL && p3 != NULL)//两个指针开始向两头移动，取值比较
        {
            if(p3->val != p1->val)
                return false;
            p3 = p3->next;
            p1 = p1->next;
        }
        return true;//比较中没有发现不同值，则为回文链表
}