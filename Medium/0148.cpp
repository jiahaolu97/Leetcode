class Solution {
public:
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }else{
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }
        if(l1){
            p->next = l1;
        }
        if(l2){
            p->next = l2;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* prev,*slow,*fast;
        prev = head;
        slow = head;
        fast = head;
        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        ListNode* res = merge(l1,l2);
        return res;
    }
};
