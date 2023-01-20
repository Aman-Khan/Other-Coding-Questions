
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        ListNode* nthNode=head;
        
        for(int i=0; i<n; i++){
            temp=temp->next;
        }
        if(!temp) return nthNode->next;

        while(temp->next){
            temp = temp->next;
            nthNode = nthNode->next;
        }
        ListNode* conn = nthNode->next;
        nthNode->next = conn->next;
        return head;
    }
