class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int, vector<pair<int, int>>> map1;
        vector<int> ans(n, INT_MAX);
        for (auto& it : redEdges) {
            map1[it[0]].push_back({it[1], 0});
        }
        for (auto& it : blueEdges) {
            map1[it[0]].push_back({it[1], 1});
        }
        queue<pair<pair<int, int>, int>> q; 
        q.push({{0, -1}, 0}); 
        vector<vector<bool>> visited(n, vector<bool>(2, false)); 

        while (!q.empty()) {
            auto [top, dist] = q.front(); q.pop();
            int node = top.first, col = top.second;
            ans[node] = min(ans[node], dist);
            for (auto& [node2, color] : map1[node]) {
                if (!visited[node2][color] && color != col) {
                    visited[node2][color] = true;
                    q.push({{node2, color}, dist + 1});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (ans[i] == INT_MAX) ans[i] = -1;
        }

        return ans;
    }
};
