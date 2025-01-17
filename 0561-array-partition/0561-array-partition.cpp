class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=0;
        for(int i=0;i<n;i+=2){
            maxi+=min(nums[i],nums[i+1]);
        }
        return maxi;
    }
};