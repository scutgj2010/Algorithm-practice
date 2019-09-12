struct ListNode * RevList(struct ListNode *head,struct ListNode *pPrev )
{
    struct ListNode * pNext;
    if (head->next!=NULL)
    {
       pNext=head->next;
       head->next=pPrev;
       return RevList(pNext,head);      
    }
    else
    {
        head->next=pPrev;
        return head;
    }
}

struct ListNode* reverseList(struct ListNode* head){
    if(NULL == head)
    {
        return head;
    }
    return RevList(head,NULL);
}