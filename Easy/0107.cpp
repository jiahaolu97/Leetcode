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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        stack<vector<int>> layer;
        queue<TreeNode*> q;
        int num = 1;
        int cnt = 0;
        TreeNode* cur = root;
        q.push(root);
        vector<int> line;
        while(q.size()>0){
            while(num--){
                cur = q.front();
                q.pop();
                if(cur->left){ 
                    q.push(cur->left);
                    cnt++;
                }
                if(cur->right){
                    q.push(cur->right);
                    cnt++;
                }
                line.push_back(cur->val);
            }
            layer.push(line);
            line.clear();
            num = cnt;
            cnt = 0;
        }
        while(layer.size()){
            res.push_back(layer.top());
            layer.pop();
        }
        return res;
    }
};
