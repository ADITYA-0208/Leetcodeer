class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;

        int n = heightMap.size();
        int m = heightMap[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][m - 1], {i, m - 1}});
            visited[i][0] = visited[i][m - 1] = true;
        }
        for (int j = 1; j < m - 1; j++) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[n - 1][j], {n - 1, j}});
            visited[0][j] = visited[n - 1][j] = true;
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int res = 0;

        while (!pq.empty()) {
            auto [height, it] = pq.top();
            pq.pop();
            int x = it.first, y = it.second;

            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    res += max(0, height - heightMap[nx][ny]);
                    pq.push({max(height, heightMap[nx][ny]), {nx, ny}});
                }
            }
        }

        return res;
    }
};
// class Solution {
// public:
//     int trapRainWater(vector<vector<int>>& heightMap) {
//         return trap(heightMap);
//     }  

//     int trap(vector<vector<int>>& height) {
//         int n = height.size();
//         int m = height[0].size();

//         vector<vector<int>> rightmax(n, vector<int>(m, 0));
//         vector<vector<int>> topmax(n, vector<int>(m, 0));
//         vector<vector<int>> bottommax(n, vector<int>(m, 0));
//         vector<vector<int>> leftmax(n, vector<int>(m, 0));

//         // Fill rightmax
//         for (int i = 0; i < n; i++) {
//             rightmax[i][m - 1] = height[i][m - 1];
//             for (int j = m - 2; j >= 0; j--) {
//                 rightmax[i][j] = max(rightmax[i][j + 1], height[i][j]);
//             }
//         }

//         // Fill topmax
//         for (int j = 0; j < m; j++) {
//             topmax[0][j] = height[0][j];
//             for (int i = 1; i < n; i++) {
//                 topmax[i][j] = max(topmax[i - 1][j], height[i][j]);
//             }
//         }

//         // Fill bottommax
//         for (int j = 0; j < m; j++) {
//             bottommax[n - 1][j] = height[n - 1][j];
//             for (int i = n - 2; i >= 0; i--) {
//                 bottommax[i][j] = max(bottommax[i + 1][j], height[i][j]);
//             }
//         }

//         // Fill leftmax
//         for (int i = 0; i < n; i++) {
//             leftmax[i][0] = height[i][0];
//             for (int j = 1; j < m; j++) {
//                 leftmax[i][j] = max(leftmax[i][j - 1], height[i][j]);
//             }
//         }

//         // Calculate trapped water
//         int res = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (height[i][j] < leftmax[i][j] && 
//                     height[i][j] < rightmax[i][j] && 
//                     height[i][j] < topmax[i][j] && 
//                     height[i][j] < bottommax[i][j]) {
//                     res += min(min(leftmax[i][j], rightmax[i][j]),
//                                min(topmax[i][j], bottommax[i][j])) - height[i][j];
//                 }
//             }
//         }

//         return res;
//     }
// };
