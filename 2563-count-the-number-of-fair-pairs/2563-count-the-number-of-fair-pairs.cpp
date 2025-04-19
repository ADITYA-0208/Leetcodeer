class Solution {
public:
    int fucc1(vector<int>nums,int start,int target){
        int left = start, right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
    int fucc2(vector<int>nums,int start,int target){
         int left = start, right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int low=fucc1(nums,i+1,lower-nums[i]);
            int high=fucc2(nums,i+1,upper-nums[i]);

            count+=high-low;
        }
        return count;
    }
};