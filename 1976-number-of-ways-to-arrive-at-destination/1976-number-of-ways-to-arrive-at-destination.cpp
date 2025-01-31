class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        int mod = 1e9 + 7;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
        vector<long long> dist(n, INT_MAX), ways(n, 1);
        
        q.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;
        
        while (!q.empty()) {
            auto [dis, x] = q.top();
            q.pop();
            for (auto it : adj[x]) {
                long long newDist = it.second + dis;
                if (newDist < dist[it.first]) {
                    dist[it.first] = newDist;
                    q.push({newDist, it.first});
                    ways[it.first] = ways[x];
                } 
                else if (newDist == dist[it.first]) {
                    ways[it.first] = (ways[it.first] + ways[x]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};
