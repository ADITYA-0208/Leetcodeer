class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total=0,sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        for(int i=0;i<nums.size()-1;i++){
            sum+=nums[i];
            total-=nums[i];
            if(sum>=total)  count++;
        }
        return count;
    }
};