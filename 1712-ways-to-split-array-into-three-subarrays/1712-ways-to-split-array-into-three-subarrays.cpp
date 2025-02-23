class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        int count = 0;
        int mod = 1e9 + 7;
        int r = 0, m = 0;
        
        for (int l = 0; l < n - 2; l++) {
            while (m <= l || (m < n - 1 && prefix[m] - prefix[l] < prefix[l])) {
                m++;
            }
            while (r < n - 1 && prefix[r] - prefix[l] <= prefix[n - 1] - prefix[r]) {
                r++;
            }
            if (m < r) {
                count = (count + (r - m)) % mod;
            }
        }

        return count;
    }
};
