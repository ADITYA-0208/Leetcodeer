class Solution {
public:
    int find1(int node, unordered_map<int, int>& parent) {
        if (parent.find(node) == parent.end()) {
            parent[node] = node; 
            return node;
        }
        if (parent[node] != node) {
            parent[node] = find1(parent[node], parent);
        }
        return parent[node];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, int> parent;
        vector<int> ans(2, 0);

        if (edges.size() < 2) return ans; 

        for (auto& it : edges) {
            int root1 = find1(it[0], parent); 
            int root2 = find1(it[1], parent); 

            if (root1 == root2) {
                ans[0] = it[0];
                ans[1] = it[1];
            } else {
                parent[root1] = root2;
            }
        }
        return ans;
    }
};

//         unordered_set<int>uni;
//         vector<int> ans(2,0);
//         if(edges.size()<=2)     return ans;
//         for(auto it :edges){
//             if(uni.find(it[0])==uni.end() ||uni.find(it[1])==uni.end()){
//                 uni.insert(it[0]);
//                 uni.insert(it[1]);
//             }
//             else{
//                 ans[0]=it[0];
//                 ans[1]=it[1];
                
//             }
//         }
//         return ans;