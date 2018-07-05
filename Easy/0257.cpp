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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        queue<vector<TreeNode*>> q;
        vector<TreeNode*> head;
        head.push_back(root);
        q.push(head);
        int cur = 1;
        int num = 0;
        while(cur--){
            vector<TreeNode*> t = q.front();
            q.pop();
            TreeNode* tail = t[t.size()-1];
            if(tail->left){
                vector<TreeNode*> x(t);
                x.push_back(tail->left);
                q.push(x);
                num++;
            }
            if(tail->right){
                vector<TreeNode*> x(t);
                x.push_back(tail->right);
                q.push(x);
                num++;
            }
            else if(!tail->left && !tail->right){
                int len = t.size();
                string line;
                for(int i=0;i<len;i++){
                    line.append(to_string(t[i]->val));
                    if(i!=len-1) line.append("->");
                }
                res.push_back(line);
            }
            if(cur == 0){
                cur = num;
                num = 0;
            }
        }
        return res;
    }
};
