class Solution {
public:
    void change(vector<int>&nums, int i){
        nums[i]^=1;
        nums[i+1]^=1;
        nums[i+2]^=1;
        return ;
    }
    int minOperations(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==0){
                change(nums,i);
                count++;
            }
        }
        int n=nums.size();
        if(nums[n-1]==0 || nums[n-2]==0)    return -1;
        return count;
    }
};