class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = findMin(nums);
        if(n==2){
            if(nums[0]==target) return 0;
            else if(nums[1]==target)    return 1;
            else return -1;
        }
        int h = (l + n) % n;
        int p = n - l;
        int he = (h + p) % n;
        int le = (l + p) % n;

        while (he <= le) {
            int mide = le + (he - le) / 2;
            int mid = (mide - p + n) % n; 
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                he = mid + 1;
            } else {
                le = mid - 1;
            }
        }
        return -1; 
    }

    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};
