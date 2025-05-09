class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int need=target-nums[i];
            if(mp.find(need)!=mp.end()){
                ans.push_back(i);
                ans.push_back(mp[need]);
                
                return ans;
            }
            
            mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};