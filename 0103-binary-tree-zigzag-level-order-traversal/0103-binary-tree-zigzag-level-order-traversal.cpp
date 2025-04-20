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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>ans2;
        if(root==NULL)  return ans2;
        queue<TreeNode*>st;
        st.push(root);
        int k=0;
        while(!st.empty()){
            vector<int>ans;
            k++;
            int size=st.size();
            for(int i=0;i<size;i++){
                TreeNode* top=st.front();
                ans.push_back(top->val);
                st.pop();

                if(top->left!=NULL) st.push(top->left);
                if(top->right!=NULL)    st.push(top->right);
            }
            if(k%2==0)  reverse(ans.begin(),ans.end());
             ans2.push_back(ans);
        }
       
        return ans2;
    }
};