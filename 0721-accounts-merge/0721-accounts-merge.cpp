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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>map1;
        unordered_map<int,int>parent;
        unordered_map<int, set<string>> mergedAccounts; 
        vector<vector<string>> ans;
        int k=0;
        for(auto it: accounts){
            for(int i=1;i<it.size();i++){
                if(map1.find(it[i])==map1.end()){
                    map1[it[i]]=find1(k,parent);
                }
                parent[find1(k, parent)] = find1(map1[it[i]], parent);
        }
        k++;
    }
    //copied
    for (auto& [email, idx] : map1) {
            mergedAccounts[find1(idx, parent)].insert(email);
        }
        
    for (auto& [idx, emails] : mergedAccounts) {
        vector<string> account(emails.begin(), emails.end());
        account.insert(account.begin(), accounts[idx][0]); // Add account name
        ans.push_back(account);
    }
    //till here
    return ans;
    }
};