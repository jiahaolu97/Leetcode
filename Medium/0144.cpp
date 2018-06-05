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
    vector<int> result;
    vector<int> preorderTraversal(TreeNode* root) {
        visit(root);
        return result;
    }
    
    void visit(TreeNode* t){
        if(t==NULL) return;
        result.push_back(t->val);
        if(t->left){
            visit(t->left);
        }
        if(t->right){
            visit(t->right);
        }
    }
    
};
