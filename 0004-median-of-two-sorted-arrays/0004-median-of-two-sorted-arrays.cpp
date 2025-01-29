class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1); // Ensuring nums1 is smaller

        int n = nums1.size();
        int m = nums2.size();
        int low = 0, high = n;
        int need = (m + n + 1) / 2;

        while (low <= high) {
            int mid = (low + high) / 2;
            int l1 = (mid > 0) ? nums1[mid - 1] : INT_MIN;
            int l2 = (need - mid > 0) ? nums2[need - mid - 1] : INT_MIN;
            int r1 = (mid < n) ? nums1[mid] : INT_MAX;
            int r2 = (need - mid < m) ? nums2[need - mid] : INT_MAX;

            if (l1 <= r2 && l2 <= r1) {
                if ((m + n) % 2 == 1) return max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            } 
            else if (l1 > r2)    high = mid - 1;
            else     low = mid + 1;
        }
        return 0.0; // Should never reach here
    }
};
