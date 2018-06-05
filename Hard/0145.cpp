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
    stack<TreeNode*> s;
    stack<bool> rightDone;
    stack<bool> leftDone;
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* t = root;
        bool done = false;
        while(t){
            if(done == false){
                s.push(t);
                //cout << s.top()->val << endl;
                rightDone.push(false);
                leftDone.push(false);
                done = true;
            }
            if(leftDone.top() == false){
                leftDone.pop();
                leftDone.push(true);
                if(t->left){
                    t = t->left;
                    done = false;
                    continue;
                }
            }
            if(rightDone.top() == false){
                rightDone.pop();
                rightDone.push(true);
                if(t->right){
                    t = t->right;
                    done = false;
                    continue;
                }
            }
            result.push_back(t->val);
            s.pop();
            leftDone.pop();
            rightDone.pop();
            if(s.size()<=0) break;
            t = s.top();
            done = true;
        }
        return result;
    }
};
