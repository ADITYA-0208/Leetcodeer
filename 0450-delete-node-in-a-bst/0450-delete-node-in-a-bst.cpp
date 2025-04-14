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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return NULL;
        if(root->val==key)  return fucc(root);
        TreeNode* node =root;
        while(root!=NULL){
            if(root->val>key){
                if(root->left!=NULL && root->left->val==key){
                    root->left= fucc(root->left);
                    break;
                }
                else 
                    root=root->left;
            }
            else{
                if(root->right!=NULL && root->right->val==key){
                    root->right= fucc(root->right);
                    break;
                }
                else
                    root=root->right;
            }
        }
        return node;
    }
    TreeNode* fucc(TreeNode* root){
        if(root->left==NULL) return root->right;
        if(root->right==NULL) return root->left;
        TreeNode* rightchild= root->right;
        TreeNode* left1=root->left;
        while(left1->right!=NULL){
            left1=left1->right;
        }
        left1->right=rightchild;
        return root->left;
    }
};