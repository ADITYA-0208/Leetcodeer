class Solution {
public:
    int fucc(int i,int j,vector<int>& nums){
        if(i==nums.size())    return 0;

        int not1=0+fucc(i+1,j,nums);
        int pick=0;
        if (j== -1||nums[i]>nums[j]){
            pick = 1+fucc(i+1,i,nums);
        }
        return max(pick,not1);
    }
    int lengthOfLIS(vector<int>& nums) {
        return fucc(0,-1,nums);
    }
};