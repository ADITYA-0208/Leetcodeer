class Solution {
public:
    // int fucc(int i,int j,vector<int>&nums){
    //     int totalwaste=0;
    //     if(i>j)    return 0;
    //     int maxi=*max_element(nums.begin()+i,nums.begin()+j);
    //     for(int k=i;k<=j;k++){
    //         totalwaste+=abs(maxi-nums[k]);
    //     }
    //     return totalwaste;
    // }
    int fucc(int i, int j, vector<int>& nums) {
        if (i > j) return 0;
        int maxi = 0;
        int sum = 0;
        for (int k = i; k <= j; k++) {
            maxi = max(maxi, nums[k]);
            sum += nums[k];
        }
        int length = j - i + 1;
        return maxi * length - sum;
    }

    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(k+1,1e9));
        vector<int>suffix(n,0);
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],nums[i]);
        }

        for(int i=0;i<n;i++){
            dp[i][0]=fucc(0,i,nums);
        }
        for(int p=1;p<=k;p++){
            for(int i=0;i<n;i++){
                for(int j=0;j<i;j++){
                    dp[i][p]=min(dp[i][p],dp[j][p-1]+fucc(j+1,i,nums));
                }
            }
        }
        return dp[n-1][k];
    }
};