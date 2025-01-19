
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;

        int n = heightMap.size();
        int m = heightMap[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        // Push all boundary cells into the priority queue
        for (int i = 0; i < n; i++) {
            pq.emplace(heightMap[i][0], i, 0);
            pq.emplace(heightMap[i][m - 1], i, m - 1);
            visited[i][0] = visited[i][m - 1] = true;
        }
        for (int j = 1; j < m - 1; j++) {
            pq.emplace(heightMap[0][j], 0, j);
            pq.emplace(heightMap[n - 1][j], n - 1, j);
            visited[0][j] = visited[n - 1][j] = true;
        }

        // Directions for neighbors (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int res = 0;

        // Process cells in the priority queue
        while (!pq.empty()) {
            auto [height, x, y] = pq.top();
            pq.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    res += max(0, height - heightMap[nx][ny]);
                    pq.emplace(max(height, heightMap[nx][ny]), nx, ny);
                }
            }
        }

        return res;
    }
};
