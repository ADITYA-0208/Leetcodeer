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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* node1=new TreeNode(val);
        TreeNode* point=root;
        TreeNode* point2=root;
        if(root->val<val){
            node1->left=root;
            return node1;
        }
        while(point2->right!=NULL && point2->right->val>val){
               point2=point2->right;
        }
        node1->left = point2->right;
        point2->right = node1;
        return root;
    }
};