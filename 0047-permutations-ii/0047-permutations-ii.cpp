class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> s;
        vector<vector<int>> ans;
        int ind = 0;  
        fucc(used, s, ans, nums, ind);
        return ans;
    }

    void fucc(vector<bool> used, vector<int>& s, vector<vector<int>>& ans, vector<int>& nums, int ind) {
        if (s.size() == nums.size()) {
            ans.push_back(s);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue; 
            
            used[i] = true;
            s.push_back(nums[i]);
            fucc(used,s,ans,nums,ind);
            s.pop_back();
            used[i] = false;
        }
    }
};
