/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a = getChain(root1);
        vector<int> b = getChain(root2);
        if(a.size()!=b.size()) return false;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
    
    vector<int> getChain(TreeNode* r){
        stack<TreeNode*> q;
        vector<int> res;
        q.push(r);
        while(q.size()>0){
            TreeNode* t = q.top();
            q.pop();
            if(t->right){
                q.push(t->right);
            }
            if(t->left){
                q.push(t->left);
            }
            if(!t->left && !t->right){
                res.push_back(t->val);
            }
        }
        return res;
        
    }
};
