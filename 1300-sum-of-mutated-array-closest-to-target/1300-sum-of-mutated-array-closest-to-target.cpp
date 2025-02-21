class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int ans = abs(sum - target);
        int best = high; 
        int n=arr.size();
        int mini=*min_element(arr.begin(), arr.end());
        if((sum/n)>target) return 0;

        while (low <= high) {
            int k = sum;
            int mid = (low + high) / 2;

            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] > mid) {
                    k -= (arr[i] - mid);
                }
            }

            if (abs(k - target) < ans) {  
                ans = abs(k - target);
                best = mid;  
            }

            if (k >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return best;
    }
};
