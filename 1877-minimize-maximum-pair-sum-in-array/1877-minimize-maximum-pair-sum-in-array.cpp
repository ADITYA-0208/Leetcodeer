class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=0;
        int n=nums.size();
        for(int i=0;i<nums.size()/2;i++){
            int sum=nums[i]+nums[n-1-i];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};