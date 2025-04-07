class Solution {
public:
    int fucc(int i, int buy, vector<int>& prices) {
        if (i == prices.size()) return 0;
        long long pro = 0;
        if (buy == 1)
            pro = max(-prices[i] + fucc(i + 1, 0, prices), fucc(i + 1, 1, prices));
        else
            pro = max(prices[i] + fucc(i + 1, 1, prices), fucc(i + 1, 0, prices));
        return (int)pro;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        long long pro=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy==0)    pro=max(0+dp[i+1][0],-prices[i]+dp[i+1][1]);
                if(buy==1)    pro=max(0+dp[i+1][1],prices[i]+dp[i+1][0]);
                dp[i][buy] = pro;
            }
        }
        return dp[0][0];
    }
};