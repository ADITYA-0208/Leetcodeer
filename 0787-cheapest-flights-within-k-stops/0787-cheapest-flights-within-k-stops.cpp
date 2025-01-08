class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        using T = pair<int, pair<int, int>>;
        priority_queue<T, vector<T>, greater<T>> q;

        vector<vector<pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        }

        q.push({0, {src, 0}});

        while (!q.empty()) {
            T top = q.top();
            q.pop();
            int t = top.first;
            int x = top.second.first;
            int s = top.second.second;

            if (x == dst) {
                return t;
            }

            if (s > k) continue;

            for (auto& neighbor : adj[x]) {
                int next_n = neighbor.first;
                int nextt = neighbor.second;
                int new_cost = t + nextt;

                q.push({new_cost, {next_n, s + 1}});
            }
        }
        return -1;
    }
};
