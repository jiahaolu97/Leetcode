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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multimap<int,int> m;     // first int value,second int index
        for(int i=0;i<lists.size();i++){
            if(lists[i])
                m.insert(pair<int,int>(lists[i]->val,i));
        }
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while(m.size()){
            int pos = m.begin()->second;
            cur->next = lists[pos];
            lists[pos] = lists[pos]->next;
            if(!lists[pos]) m.erase(m.begin());
            else{
                m.erase(m.begin());
                m.insert(pair<int,int>(lists[pos]->val,pos));
            }
            cur = cur->next;
        }
        return head->next;
    }
};
