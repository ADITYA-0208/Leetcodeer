class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        
        vector<pair<int,int>> ans;
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Start BFS from all boundary 'O's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Check boundary conditions
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && board[i][j] == 'O') {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Perform BFS
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            ans.push_back({i, j});

            for (int k = 0; k < 4; k++) {
                int newi = i + dr[k];
                int newj = j + dc[k];

                if (newi >= 0 && newi < n && newj >= 0 && newj < m && visited[newi][newj] == 0 && board[newi][newj] == 'O') {
                    q.push({newi, newj});
                    visited[newi][newj] = 1;
                }
            }
        }

        // Flip unvisited 'O's to 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && visited[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
