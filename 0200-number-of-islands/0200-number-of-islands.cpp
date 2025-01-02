class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<char>>& visited, int row, int col, int n, int m) {
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = 1; 
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            int i = top.first;
            int j = top.second;
            for (auto [di, dj] : directions) {
                int ni = i + di;
                int nj = j + dj;
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '1' && !visited[ni][nj]) {
                    q.push({ni, nj});
                    visited[ni][nj] = 1; 
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<char>> visited(n, vector<char>(m, 0));
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    cnt++;
                    bfs(grid, visited, i, j, n, m);
                }
            }
        }
        return cnt;
    }
};
