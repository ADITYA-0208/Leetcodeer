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
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,bool>map1;
        return dfs(root,k,map1);
    }
    bool dfs(TreeNode* root,int k,unordered_map<int,bool>&map1){
        if(root==NULL)  return false;
        int complement = k-root->val;
        if(map1[complement])    return true;
        map1[root->val]=true;
        return dfs(root->left,k,map1) || dfs(root->right,k,map1);
    }
};