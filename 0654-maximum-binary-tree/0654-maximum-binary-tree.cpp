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
    TreeNode* fucc(int l,int r,vector<int>&nums){
        if(l>r) return nullptr;
        int maxi=INT_MIN,ind=-1;
        for(int i=l;i<=r;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                ind=i;
            }
        }
        TreeNode* node1= new TreeNode(maxi);
        node1->right=fucc(ind+1,r,nums);
        node1->left=fucc(l,ind-1,nums);
        return node1;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        int maxi=0,ind=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                ind=i;
            }
        }
        TreeNode* node1= new TreeNode(maxi);
        TreeNode* head= node1;
        node1->right=fucc(ind+1,n-1,nums);
        node1->left=fucc(0,ind-1,nums);
        return head;
    }
};