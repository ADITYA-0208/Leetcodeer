class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int maxi = 0, ans = 0;
            for (int j = 0; j < k && i - j >= 0; j++) {
                maxi = max(maxi, arr[i - j]);
                ans = max(ans, (j + 1) * maxi+ dp[i - j]);
            }

            dp[i + 1] = ans;  
        }

        return dp[n];
    }
};