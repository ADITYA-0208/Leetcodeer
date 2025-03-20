class Solution {
    #define pii pair<int,int>

    int find(vector<int>& dsuf,int v){
        if(dsuf[v]==-1)
            return v;
        return dsuf[v] = find(dsuf,dsuf[v]);
    }
    void traverseComponent(int& bitwise_and,int curr,vector<bool>& visited,vector<vector<pii>>& adj){
        visited[curr] = true;
        for(auto& [nbr,wt]: adj[curr]){
            bitwise_and &= wt;
            if(!visited[nbr])
                traverseComponent(bitwise_and,nbr,visited,adj);
        }
    }
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        //Step-1: Keep components segregated using disjoint set and make Adj-List
        vector<int> dsuf(n,-1);
        vector<vector<pii>> adj(n);
        for(auto& edge: edges){
            adj[edge[0]].push_back(make_pair(edge[1],edge[2]));
            adj[edge[1]].push_back(make_pair(edge[0],edge[2]));

            int px = find(dsuf,edge[0]);
            int py = find(dsuf,edge[1]);
            if(px != py)
                dsuf[px] = py;
        }

        //Step-2: Precompute minimum walk cost for each component
        unordered_map<int,int> parent_cost;
        vector<bool> visited(n,false);
        for(int i=0;i<n;++i){
            if(!visited[i]){
                int bitwise_and = adj[i].size()==0? 0: adj[i][0].second;
                traverseComponent(bitwise_and,i,visited,adj);
                int parent = find(dsuf,i);
                parent_cost[parent] = bitwise_and;
            }
        }
        //Step-3: Calculate each query
        vector<int> ans;
        for(auto& q: query){
            int px = find(dsuf,q[0]);
            int py = find(dsuf,q[1]);
            if(px==py)  ans.push_back(parent_cost[px]);
            else        ans.push_back(-1);
        }
        return ans;
    }
};  

// class Solution {
// private:
//     int fucc(int i,vector<int>parent){
//         if(parent[i]==-1)   return i;
//         return parent[i]=fucc(parent[i],parent);
//     }
//     void fucc2(int& and1,int i,vector<bool>&visited,vector<vector<pair<int,int>>>&adj){
//         visited[i]=true;
//         for(auto it: adj[i]){
//             and1&=it.second;
//             if(!visited[it.first]){
//                 fucc2(and1,it.first,visited,adj);
//             }
//         }
//     }
// public:
//     vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
//         vector<vector<pair<int,int>>>adj(n);
//         vector<int>parent(n,-1);
//         for (auto& edge : edges) {
//             adj[edge[0]].push_back({edge[1], edge[2]});
//             adj[edge[1]].push_back({edge[0], edge[2]});

//             int p1=fucc(edge[1],parent);
//             int p2=fucc(edge[0],parent);
//             if(p1!=p2)  parent[p1]=p2;
//         }
//         unordered_map<int,int> cost;
//         vector<bool> visited(n,false);
//         for(int i=0;i<n;++i){
//             if(!visited[i]){
//                 int and1=adj[i].size()==0? 0: adj[i][0].second;
//                 fucc2(and1,i,visited,adj);
//                 int p3=fucc(i,parent);
//                 cost[p3]=and1;
//             }
//         }
//         vector<int>ans;
//         for(auto it : query){
//             int px = fucc(it[0],parent);
//             int py = (it[1],parent);
//             if(px==py)  ans.push_back(cost[px]);
//             else        ans.push_back(-1);
//         }
//         return ans;
//     }
// };