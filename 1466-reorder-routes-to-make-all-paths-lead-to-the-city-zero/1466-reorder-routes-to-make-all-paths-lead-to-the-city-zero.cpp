class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int, bool>>> graph;
        unordered_set<int> visited;
        int k = 0;
        for (auto& conn : connections) {
            graph[conn[0]].emplace_back(conn[1], true);
            graph[conn[1]].emplace_back(conn[0], false); 
        }
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int t=q.front();
            q.pop();
            visited.insert(t);
            for(auto [it,tf]: graph[t]){
                if(visited.find(it)==visited.end()){
                if(tf){
                    k++;
                }
                q.push(it);
                visited.insert(it);}
            }   
            
        }

        return k;
    }
};
