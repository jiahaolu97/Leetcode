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
    stack<TreeNode*> s;
    vector<int> result;
    vector<int> inorderTraversal(TreeNode* root) {
        visit(root);
        return result;
    }
    
    void visit(TreeNode* t){
        if(t == NULL) return;
        if(t->left){
            s.push(t);
            visit(t->left);
        }
        result.push_back(t->val);
        if(t->right){
            s.push(t);
            visit(t->right);
        }
        return;
    }
    
};
