class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int k=0,maxi=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                k++;
                maxi=max(maxi,k);
            }
            else{
                k=0;
            }
        }
        int k2=0,maxi2=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                k2++;
                maxi2=max(maxi2,k2);
            }
            else{
                k2=0;
            }
        }
        return max(maxi,maxi2)+1;
    }
};