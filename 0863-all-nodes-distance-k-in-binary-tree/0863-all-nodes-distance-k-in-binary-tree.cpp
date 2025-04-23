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
    TreeNode* findparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&map1,TreeNode*target){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode*ans;
        while(!q.empty()){

            TreeNode* node=q.front();
            q.pop();
            if(node==target)    ans=node;
            if(node->left){
                q.push(node->left);
                map1[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                map1[node->right]=node;
            }
        }
        return ans;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<pair<TreeNode*,int>>q;
        unordered_map<TreeNode*,TreeNode*>map1;
        TreeNode* node1=findparent(root,map1,target);
        unordered_map<TreeNode*,bool>visited;
        q.push({node1,k});
        vector<int>ans;
        while(!q.empty()){

            auto& [node,it]=q.front();
            q.pop();
            visited[node]=true;
            if(it==0)   ans.push_back(node->val);
            if(node->left && visited[node->left]==false){
                q.push({node->left,it-1});
            }
            if(node->right && visited[node->right]==false){
                q.push({node->right,it-1});
            }
            if(map1.find(node)!=map1.end() && visited[map1[node]]==false){
                q.push({map1[node],it-1});
            }
        }
        return ans;
    }
};