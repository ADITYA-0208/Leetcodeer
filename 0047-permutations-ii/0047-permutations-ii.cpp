class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> s;
        vector<bool> used(nums.size(), false);
        
        sort(nums.begin(), nums.end());  
        
        backtrack(nums, used, s, ans);
        return ans;
    }
    
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& s, vector<vector<int>>& ans) {
        if (s.size() == nums.size()) {
            ans.push_back(s);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue; // Skip duplicates
            
            used[i] = true;
            s.push_back(nums[i]);
            backtrack(nums, used, s, ans);
            s.pop_back();
            used[i] = false;
        }
    }
};
