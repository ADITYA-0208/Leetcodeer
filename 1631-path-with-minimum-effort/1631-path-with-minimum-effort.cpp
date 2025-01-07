class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        using T = pair<int, pair<int, int>>;
        priority_queue<T, vector<T>, greater<T>> q;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> distance(n, vector<int>(m, 1e9));
        q.push({0, {0, 0}});
        distance[0][0] = 0;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto top = q.top();
            q.pop();
            int r = top.second.first;
            int c = top.second.second;
            int d = top.first;

            if (r == n - 1 && c == m - 1) return d;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    int nreffort = max(abs(heights[r][c] - heights[nr][nc]), d);
                    if (nreffort < distance[nr][nc]) {
                        distance[nr][nc] = nreffort;
                        q.push({nreffort, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};
