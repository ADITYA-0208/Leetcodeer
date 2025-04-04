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
    int maxi=0;
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<TreeNode*,int>map1;
        int n=maxDepth(root,map1,0);
        return lowestCommonAncestor(root,map1);
    }
    int maxDepth(TreeNode* root,unordered_map<TreeNode*,int> &map1,int d) {
        if(root==NULL){
            return 0;
        }
        maxi=max(maxi,d);
        map1[root]=d;
        int l=maxDepth(root->left,map1,d+1);
        int r=maxDepth(root->right,map1,d+1);
        return max(l,r)+1;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root,unordered_map<TreeNode*,int>map1) {
        if(root==NULL || map1[root]==maxi){
            return root;
        }
        
        TreeNode* left=lowestCommonAncestor(root->left,map1);
        TreeNode* right=lowestCommonAncestor(root->right,map1);
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }
        else{
            return root;
        }
    }
};