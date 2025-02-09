class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> map1;
        int n = nums.size();
        long long good = 0;
        for (int i = 0; i < n; i++) {
            if(map1.count(nums[i]-i))   good += map1[nums[i] - i];
            map1[nums[i] - i]++;
        }
        return (1LL * n * (n - 1) / 2) - good;//n * (n - 1) / 2 may cause overflow,
        // so 1LL * n * (n - 1) / 2 ensures correct computation.
    }
};
