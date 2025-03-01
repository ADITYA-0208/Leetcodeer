class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INT_MAX) continue;  

            for (int j = 1; j <= nums[i]; j++) {  
                if (i + j < n) 
                    dp[i + j] = min(dp[i] + 1, dp[i + j]);
                else 
                    break;
            }
        }
        
        return dp[n - 1] != INT_MAX;
    }
};
