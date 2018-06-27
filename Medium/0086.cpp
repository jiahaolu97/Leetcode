/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode* smallHead = new ListNode(0);
        ListNode* bigHead = new ListNode(0);
        ListNode* cur = head;
        ListNode* small = smallHead;
        ListNode* big = bigHead;
        bool smallFirst = true;
        bool bigFirst = true;
        bool smallLast = true;
        while(cur){
            int v = cur->val;
            if(v<x){
                if(!smallFirst)
                    small = small->next;
                small->next = cur;
                smallFirst = false;
                smallLast = true;
            }else{
                if(!bigFirst)
                    big = big->next;
                big->next = cur;;
                bigFirst = false;
                smallLast = false;
            }
            cur = cur->next;
        }
        if(small->next)
            small->next->next = bigHead->next;
        if(big->next)
            big->next->next = NULL;
        if(smallHead->next)
            return smallHead->next;
        return bigHead->next;
    }
};
