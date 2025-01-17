class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int mini=1e9;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            int sub=abs(nums[i]-nums[i+1]);
            mini=min(mini,sub);
        }
        return mini;
    }
};