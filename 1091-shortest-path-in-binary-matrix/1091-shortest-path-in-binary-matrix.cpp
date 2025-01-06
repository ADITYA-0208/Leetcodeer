class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        q.push({1, {0, 0}});
        dis[0][0] = 1;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int u = it.second.first, v = it.second.second, d = it.first;

            if (u == n - 1 && v == n - 1) return d;

            for (int i = 0; i < 8; ++i) {
                int ni = u + directions[i][0], nj = v + directions[i][1];
                if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 0 && d + 1 < dis[ni][nj]) {
                    dis[ni][nj] = d + 1;
                    q.push({d + 1, {ni, nj}});
                }
            }
        }
        return -1;
    }
};
