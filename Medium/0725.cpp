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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res;
        // if(!root){
        //     res.push_back(root);
        //     return res;
        // }
        int len = 0;
        ListNode* cur = root;
        
        while(cur){
            len++;
            cur = cur->next;
        }
        int base = len/k;
        int remain = len%k;
        cur = root;
        for(int i=0;i<k;i++){
            ListNode* group = cur;
            if(i<remain){   //base+1
                for(int j=0;j<base+1;j++){
                    ListNode* tmp = cur;
                    cur = cur->next;
                    if(j == base)
                        tmp->next = NULL;
                }
            }else{  //base;
                for(int j=0;j<base;j++){
                    ListNode* tmp = cur;
                    cur = cur->next;
                    if(j == base-1)
                        tmp->next = NULL;
                }
            }
            res.push_back(group);
        }
        return res;
    }
};
