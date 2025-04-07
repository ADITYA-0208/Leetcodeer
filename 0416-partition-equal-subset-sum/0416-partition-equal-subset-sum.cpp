class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        
        if(sum%2!=0){
            return false;
        }      
        cout<<sum; 
        sum=ceil(sum/2); 
        cout<<"   "<<sum;
        return fucc(nums, sum, n);
    }
    bool fucc(vector<int>& arr, int sum, int n) {
        
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        if(n==1){
            if(arr[0]==sum){
                dp[0][arr[0]]=true;
            }}
            for(int i=0;i<n;i++){
                dp[i][0]=true;
            }
            bool pick=false;
            bool notpick=false;
            for(int i=1;i<n;i++){
                for(int k=1;k<=sum;k++){
                    if (arr[i] <= k){
                        pick=dp[i-1][k-arr[i]];
                    }
                    notpick=dp[i-1][k];
                    dp[i][k]=pick||notpick;
                }
            }
        return dp[n - 1][sum];
    }

};