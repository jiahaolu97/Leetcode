/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> s;
    TreeNode* cur;
    
    BSTIterator(TreeNode *root) {
        visit(root);
        cur = NULL;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return  s.size();
    }

    /** @return the next smallest number */
    int next() {
        int val = s.top()->val;
        s.pop();
        return val;
    }
private:
    void visit(TreeNode* t){
        if(t == NULL) return;
        if(t->right){
            visit(t->right);
        }
        s.push(t);
        if(t->left){
            visit(t->left);
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
