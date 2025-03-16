class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ma=*max_element(nums.begin(),nums.end());
        if(ma<0)    return ma;
        unordered_set<int> set1(nums.begin(), nums.end());
        int sum=0;
        for (int num : set1) {
            if(num>0)    sum += num;
        }
        return sum;
    }
};