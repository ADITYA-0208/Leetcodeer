class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int count=0,i=0,n=nums.size();
        for(i=0;i<nums.size();i++){
            if(nums[i]<0)    count++;
            else if(nums[i]==0)  continue;
            else break;
        }
        return max(count,n-i);
    }
};