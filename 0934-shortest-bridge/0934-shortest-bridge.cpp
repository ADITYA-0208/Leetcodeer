class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        bool found = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    bfs(grid, q, i, j);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int k = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int z = 0; z < size; z++) {
                auto top = q.front();
                q.pop();
                int i = top.first;
                int j = top.second;
                for (auto [di, dj] : directions) {
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if (grid[ni][nj] == 1) {
                            return k; 
                        }
                        if (grid[ni][nj] == 0) {
                           // grid[ni][nj] = 1; 
                            q.push({ni, nj});
                        }
                    }
                }
            }
            k++; 
        }
        return -1;
    }
    void bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        grid[i][j] = -1; 
        q.push({i, j}); 

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto [di, dj] : directions) {
            int ni = i + di, nj = j + dj;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1) {
                bfs(grid, q, ni, nj);
            }
        }
    }
};
