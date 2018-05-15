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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        int max = -1e8;
        int idx = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max){
                max = nums[i];
                idx = i;
            }
        }
        vector<int> left;
        vector<int> right;
        for(int i=0;i<nums.size();i++){
            if(i<idx) left.push_back(nums[i]);
            if(i>idx) right.push_back(nums[i]);
        }
        TreeNode* res = new TreeNode(max);
        res->left = constructMaximumBinaryTree(left);
        res->right = constructMaximumBinaryTree(right);
        return res;
    }
};
