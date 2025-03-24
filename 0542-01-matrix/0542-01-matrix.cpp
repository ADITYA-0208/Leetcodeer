
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));  // Initialize with INT_MAX
        int dr[4] = {-1, 1, 0, 0};  // Row directions (up, down)
        int dc[4] = {0, 0, 1, -1};  // Column directions (right, left)
        queue<pair<int, int>> q;

        // Enqueue all cells with '0' and initialize distance for '1's as INT_MAX
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                } else {
                    ans[i][j] = INT_MAX;
                }
            }
        }

        // Perform BFS
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m) {
                    // Update the distance if a shorter path is found
                    if (ans[newRow][newCol] > ans[row][col] + 1) {
                        ans[newRow][newCol] = ans[row][col] + 1;
                        q.push({newRow, newCol});
                    }
                }
            }
        }

        return ans;
    }
};