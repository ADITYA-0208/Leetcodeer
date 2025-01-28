class Solution {
public:
    bool fucc(vector<int>& nums, int k, int tar) {
        int p = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > tar) return false;
            if (sum + nums[i] > tar) {
                p++; 
                sum = nums[i];// ye line samaj ni aai 
            } else {
                sum += nums[i];
            }
            if (p > k) return true; 
        }
        return false; 
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        if (nums.size() == k) return low; 
        if (nums.size() < k) return -1; 
        
       // int result = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (fucc(nums, k, mid)) {
                 low = mid + 1;
            } else {
         //       result = mid; 
                high = mid - 1;
                 
            }
        }
        return low;
    }
};
