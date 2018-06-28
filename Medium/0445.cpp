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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0,len2 = 0;
        ListNode* cur = l1;
        while(cur){
            cur = cur->next;
            len1++;
        }
        cur = l2;
        while(cur){
            cur = cur->next;
            len2++;
        }
        if(len1==0) return l2;
        if(len2==0) return l1;
        int len = len1>len2?len1:len2;
        int a[len];
        int b[len];
        memset(a,0,len*sizeof(int));
        memset(b,0,len*sizeof(int));
        cur = l1;
        for(int i=len-len1;i<len;i++){
            a[i] = cur->val;
            cur = cur->next;
        }
        cur = l2;
        for(int i=len-len2;i<len;i++){
            b[i] = cur->val;
            cur = cur->next;
        }
        bool go = false;
        for(int i=len-1;i>=0;i--){
            b[i] = a[i]+b[i];
            if(go) b[i]++;
            if(b[i]>=10){
                b[i] -= 10;
                go = true;
            }else{
                go = false;
            }
        }
        ListNode* head;
        if(go) head = new ListNode(1);
        else head = new ListNode(-1);
        cur = head;
        for(int i=0;i<len;i++){
            cur->next = new ListNode(b[i]);
            cur = cur->next;
        }
        if(!go) return head->next;
        return head;
    }
};
