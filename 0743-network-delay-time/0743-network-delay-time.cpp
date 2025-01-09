class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto &time : times) {
            int u = time[0], v = time[1], w = time[2];
            adj[u].emplace_back(v, w);
        }
        vector<int> ans = dijkstra(adj, k);
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (ans[i] == 1e9) return -1;
            maxTime = max(maxTime, ans[i]);
        }
        return maxTime;
    }

    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> dis(adj.size(), 1e9);
        q.push({0, src});
        dis[src] = 0;
        while (!q.empty()) {
            auto [x, y] = q.top();
            q.pop();
            for (auto &[nx, weight] : adj[y]) {
                int ny = x + weight;
                if (dis[nx] > ny) {
                    q.push({ny, nx});
                    dis[nx] = ny;
                }
            }
        }
        return dis;
    }
};
