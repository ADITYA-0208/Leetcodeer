class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int ans = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1 && visited[i][j] == 0) {
                    if (bfs(grid1, grid2, visited, i, j)) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }

    bool bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& visited, int i, int j) {
        int n = grid1.size();
        int m = grid1[0].size();
        queue<pair<int, int>> q;
        bool flag = true;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        q.push({i, j});
        visited[i][j] = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (grid1[x][y] == 0) {
                flag = false;
            }
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid2[nx][ny] == 1 && visited[nx][ny] == 0) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        return flag;
    }
};
