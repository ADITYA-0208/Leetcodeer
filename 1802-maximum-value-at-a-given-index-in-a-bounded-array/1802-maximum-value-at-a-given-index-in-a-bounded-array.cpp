class Solution {
public:
    long formula(long count, long x) {
        if (count >= x) 
            return (x * (x - 1) / 2) + (count - x + 1);
        return count * x - (count * (count + 1) / 2);
    }

    int maxValue(int n, int index, int maxSum) {
        int l = 1, h = maxSum;
        while (l <= h) {
            int mid = l + (h - l) / 2; 
            long lcount = index;
            long rcount = n - 1 - index;

            long lsum = formula(lcount, mid);
            long rsum = formula(rcount, mid);
            long sum = lsum + rsum + mid;

            if (sum <= maxSum) { 
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return h; 
    }
};

