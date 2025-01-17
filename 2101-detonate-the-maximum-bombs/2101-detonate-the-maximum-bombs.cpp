class Solution {
public:
    void DFS(int node, unordered_set<int>& visited, unordered_map<int, vector<int>>& adj) {
        visited.insert(node);
        for (int neighbor : adj[node]) { 
            if (visited.find(neighbor) == visited.end()) {
                DFS(neighbor, visited, adj); r
            }}
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            int x1 = bombs[i][0];
            int y1 = bombs[i][1];
            int r1 = bombs[i][2];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                long long distSquared = (long long)(x2 - x1) * (x2 - x1) + (long long)(y2 - y1) * (y2 - y1);
                if ((long long)r1 * r1 >= distSquared) {
                    adj[i].push_back(j); 
                }
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> visited;
            DFS(i, visited, adj);
            result = max(result, (int)visited.size());
        }

        return result;
    }
};
