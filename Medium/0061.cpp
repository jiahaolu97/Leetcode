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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        int len = 1;
        ListNode* iter = head;
        while(iter->next){
            len++;
            iter = iter->next;
        }
        k %= len;
        int m = len - k;
        // ListNode* first = head;
        ListNode* last = new ListNode(0);
        last -> next = head;
        for(int i=0;i<m;i++){
            last = last->next;
            // first = first->next;
        }
        iter->next = head;
        ListNode* first = last->next;
        last->next = NULL;
        return first;
    }
};
