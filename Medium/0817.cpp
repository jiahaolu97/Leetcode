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
    int numComponents(ListNode* head, vector<int>& G) {
        set<int> s;
        int res = 0;
        for(int i=0;i<G.size();i++){
            s.insert(G[i]);
        }
        bool last = false;
        while(head){
            int v = head->val;
            if(s.find(v)!=s.end()){     //this one found
                if(!last) res++;
                last = true;
            }else{              //this one not found
                last = false; 
            }
            head = head->next;
        }
        return res;
    }
};
