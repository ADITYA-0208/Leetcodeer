/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<TreeNode*>inorder1;
    int i,n;
    BSTIterator(TreeNode* root) {
        inorder(root);
        i=0;
        n=inorder1.size();
    }
    void inorder(TreeNode * root){
        if(root==NULL)  return;
        inorder(root->left);
        inorder1.push_back(root);
        inorder(root->right);
    }
    int next() {
        i++;
        return inorder1[i-1]->val;
    }
    
    bool hasNext() {
        if(i<n) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */