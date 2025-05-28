class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k){
        int n = 0;
        for(auto &edge : edges1) {
            int u = edge[0], v = edge[1];
            n=max(n,max(u,v));
        }
        n += 1;
        vector<vector<int>> adj1(n);
        for (auto &edge : edges1) {
            int u = edge[0], v = edge[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        int n2 = 0;
        for (auto &edge : edges2) {
            int u = edge[0], v = edge[1];
            n2=max(n2,max(u,v));
        }
        n2+= 1;
        vector<vector<int>>adj2(n2);
        for (auto &edge : edges2) {
            int u = edge[0], v = edge[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,bfs(adj2,i,k-1));
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int x=bfs(adj1,i,k);
            ans[i]=x+maxi;
            cout<<x;
        }
        return ans;
    }
    int bfs(vector<vector<int>>&adj,int node,int k){
        if (node >= adj.size()) return 0;

        queue<pair<int,int>>q;
        vector<bool> visited(adj.size(), false);
        int count=0;
        q.push({node,0});
        visited[node]=true;
        while(!q.empty()){
            auto [node1,i]=q.front();
            q.pop();
            if(i>k) continue;
            count++;
            for(auto neighbor : adj[node1]){
                if(neighbor < adj.size() && !visited[neighbor]){
                    visited[neighbor]=true;
                    q.push({neighbor,i+1});
                }
            }
            
        }
        return count;
    }
};