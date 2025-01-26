//copied
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> visited(n, -1), stack(n, 0), depth(n, 0);
        int maxCycleSize = 0, chainSum = 0;
        function<void(int, int)> dfs = [&](int u, int d) {
            visited[u] = d;
            int v = favorite[u];
            if (visited[v] == -1) {
                dfs(v, d + 1);
            } else if (stack[v]) { 
                maxCycleSize = max(maxCycleSize, visited[u] - visited[v] + 1);
            }
            stack[u] = 0;
        };

        for (int i = 0; i < n; ++i) {
            if (visited[i] == -1) {
                stack[i] = 1;
                dfs(i, 0);
            }
        }
        vector<int> maxChain(n, 0);

        auto getChainLength = [&](int start) {
            int len = 0, current = start;
            while (visited[current] == -1) {
                len++;
                visited[current] = 0;
                current = favorite[current];
            }
            return len;
        };

        for (int i = 0; i < n; ++i) {
            if (favorite[favorite[i]] == i && i < favorite[i]) {
                maxChain[i] = getChainLength(i);
                maxChain[favorite[i]] = getChainLength(favorite[i]);
                chainSum += maxChain[i] + maxChain[favorite[i]];
            }
        }
        return max(maxCycleSize, chainSum);
    }
};