class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> map1;
        vector<vector<int>> dp(n, vector<int>(n, 2));  
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            map1[arr[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int prev = arr[j] - arr[i];
                if (prev < arr[i] && map1.find(prev) != map1.end()) {
                    int k = map1[prev];
                    dp[i][j] = dp[k][i] + 1;
                }
                maxLen = max(maxLen, dp[i][j]);
            }
        }

        return maxLen > 2 ? maxLen : 0;
    }
};
