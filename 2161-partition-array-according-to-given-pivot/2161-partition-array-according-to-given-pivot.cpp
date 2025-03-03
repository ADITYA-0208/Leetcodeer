class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int low = 0, mid = 0;
        for (int num : nums) {
            if (num < pivot) low++;
            else if (num == pivot) mid++;
        }

        int h = low + mid;
        mid = low;         
        int l = 0;
        vector<int> ans(nums.size());
        for (int num : nums) {
            if (num < pivot) ans[l++] = num;
            else if (num == pivot) ans[mid++] = num;
            else ans[h++] = num;
        }
        
        return ans;
    }
};
