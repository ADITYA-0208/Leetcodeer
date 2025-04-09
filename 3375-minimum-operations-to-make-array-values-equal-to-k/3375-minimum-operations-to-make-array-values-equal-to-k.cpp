class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        unordered_set<int>set1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>k)   set1.insert(nums[i]);
            if(nums[i]==k)  ans++;
            if(nums[i]<k)   return -1;
        }
        if(ans==nums.size())    return 0;
        if(set1.size()==0)  return -1;
        return set1.size();
    }
};