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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        vector<vector<int>> ans;
        fucc(0,0,root,nodes);
        fucc2(nodes);
        for(auto p: nodes){
            vector<int> col;
            for(auto q: p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
    void fucc(int i, int j, TreeNode* root, map<int, map<int, multiset<int>>>& nodes){
        nodes[j][i].insert(root->val);
        if(root->left!=NULL)
            fucc(i+1,j-1,root->left,nodes);
        if(root->right!=NULL)
            fucc(i+1,j+1,root->right,nodes);
        return ;
    }
    void fucc2(const map<int, map<int, multiset<int>>>& nodes) {
    for (const auto& [col, rowMap] : nodes) {
        cout << "Column " << col << ":\n";
        for (const auto& [row, vals] : rowMap) {
            cout << "  Row " << row << " -> ";
            for (int val : vals) {
                cout << val << " ";
            }
            cout << "\n";
        }
    }
}

};