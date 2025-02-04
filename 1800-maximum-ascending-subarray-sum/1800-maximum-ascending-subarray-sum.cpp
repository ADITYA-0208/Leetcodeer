class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int k=nums[0];
        int maxi=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                k+=nums[i];
                maxi=max(maxi,k);
            }
            else{
                k=nums[i];
            }
        }
        return maxi;
    }
};