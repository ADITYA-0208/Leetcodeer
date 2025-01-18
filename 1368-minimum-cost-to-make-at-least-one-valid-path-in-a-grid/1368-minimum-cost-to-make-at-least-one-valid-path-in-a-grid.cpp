struct compare {
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        return a.first > b.first; // Min-heap based on the first element of the outer pair
    }
};
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> q;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        q.push({0, {0, 0}});
        while (!q.empty()) {
            auto [cost, it] = q.top();
            q.pop();
            int x = it.first;
            int y = it.second;
            if (x == n - 1 && y == n - 1) return cost;
            if (visited[x][y]) continue;
            visited[x][y] = 1;
            int k = 0;
            for (auto [di, dj] : directions) {
                int nx = x + di, ny = y + dj;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny] == 0) {
                    int ncost = cost + (grid[x][y] - 1 == k ? 0 : 1);
                    q.push({ncost, {nx, ny}});
                }
                k++;
            }
        }
        return -1;
    }
};
