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
    map<int,int> m;
    int kthSmallest(TreeNode* root, int k) {
        Traverse(root);
        return find(k,root);
    }
    int find(int k,TreeNode* node){
        int l = 0;
        if(node->left){
            l = m[node->left->val];
        }
        if(k<=l) return find(k,node->left);
        if(k==l+1) return node->val;
        return find(k-l-1,node->right);
    }
    
    int Traverse(TreeNode* r){
        if(!r) return 0;
        int num = 1;
        if(r->left) num += Traverse(r->left);
        if(r->right) num += Traverse(r->right);
        m[r->val] = num;
        return num;
    }
    
};
