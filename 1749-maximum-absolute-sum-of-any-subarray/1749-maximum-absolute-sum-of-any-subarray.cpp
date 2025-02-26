class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        return max(abs(maxSubarraySum(nums)),abs(minSubarraySum(nums)));
    }
    int maxSubarraySum(vector<int> &arr) {
        int res = arr[0];
        int maxi = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            maxi= max(maxi + arr[i], arr[i]);
            res = max(res, maxi);
        }
        return res;
    }
    int minSubarraySum(vector<int> &arr) {
        int res = arr[0];
        int maxi = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            maxi = min(maxi + arr[i], arr[i]);
            res = min(res, maxi);
        }
        return res;
    }
};