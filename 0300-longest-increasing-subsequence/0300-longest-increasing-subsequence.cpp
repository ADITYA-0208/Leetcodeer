class Solution {
public:
    int fucc(int i,int j,vector<int>& nums,vector<vector<int>>&dp){
        if(i==nums.size())    return 0;
        if(dp[i][j+1]!=-1)    return dp[i][j+1];
        int not1=0+fucc(i+1,j,nums,dp);
        int pick=0;
        if (j== -1||nums[i]>nums[j]){
            pick = 1+fucc(i+1,i,nums,dp);
        }
        return dp[i][j+1]=max(pick,not1);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // int x=fucc(0,-1,nums,dp);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<=n;j++){
        //         cout<<dp[i][j]<<". ";
        //     }
        //     cout<<endl;
        // }
        // return x;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
        for(int i=n-1;i>=0;i--){
            for (int j=i-1;j>=-1;j--){
                int notTake = 0 + dp[i+1][j+1];
                int take = 0;
                if(j==-1||nums[i]>nums[j]){
                    take =1+dp[i+1][i+1];
                }
        
                dp[i][j+1] = max(notTake,take);
                
            }
        }
        
        return dp[0][0];
    }    
};