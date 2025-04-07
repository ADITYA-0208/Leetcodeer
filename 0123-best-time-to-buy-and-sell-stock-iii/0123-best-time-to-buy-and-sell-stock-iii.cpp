class Solution {
public:
    int fucc(int i, int buy, vector<int>& prices, int n, vector<vector<vector<int>>>& dp) {
        if (i == prices.size() || n == 0) return 0;
        if (dp[i][buy][n] != -1) return dp[i][buy][n];

        if (buy == 1)
            return dp[i][buy][n] = max(-prices[i] + fucc(i + 1, 0, prices, n , dp),
                                       fucc(i + 1, 1, prices, n, dp));
        else
            return dp[i][buy][n] = max(prices[i] + fucc(i + 1, 1, prices, n-1 ,dp),
                                       fucc(i + 1, 0, prices, n, dp));
    }

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            for(int k=1;k<=2;k++){
                if(buy==0){
                    dp[i][buy][k] = max(-prices[i] + dp[i + 1][1][k],
                                        dp[i + 1][0][k]);
                }
                else{
                    dp[i][buy][k] = max(prices[i] + dp[i + 1][0][k-1],
                                        dp[i + 1][1][k]);
                }
            }
        }
    }
    return dp[0][0][2];
}

};
