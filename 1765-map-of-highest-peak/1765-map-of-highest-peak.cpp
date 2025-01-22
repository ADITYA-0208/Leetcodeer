class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        // Min-heap priority queue
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    pq.push({0, {i, j}});
                    ans[i][j] = 0;
                }
            }
        }
        vector<pair<int, int>> direction = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while (!pq.empty()) {
            auto [it, corr] = pq.top();
            pq.pop();
            
            int x = corr.first;
            int y = corr.second;
            
            for (auto& dir : direction) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && ans[nx][ny] == -1) {
                    ans[nx][ny] = it + 1;
                    pq.push({it + 1, {nx, ny}});
                }
            }
        }
        
        return ans;
    }
};
