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
class FindElements {
public:
    unordered_set<int>val1;
    void fucc(TreeNode* node,int val){
        if(!node)   return ;
        val1.insert(val);
        fucc(node->left,2*val+1);
        fucc(node->right,2*val+2);
    }
    FindElements(TreeNode* root) {
        val1.insert(0);
        fucc(root->left,1);
        fucc(root->right,2);
    }
    
    bool find(int target) {
        if(val1.find(target)==val1.end())     return false;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */