class Solution {
public:
    const int mod = 1e9 + 7;

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long mini=0;
        generateContiguousSubarrays(arr, n,mini);
        
        return (int)mini;
    }

    void generateContiguousSubarrays(vector<int>& arr, int n, long long &mini) {
        for (int i = 0; i < n; i++) {
            int current_min = arr[i];
            for (int j = i; j < n; j++) {
                current_min = min(current_min, arr[j]); 
                mini+=(int) current_min; 
            }
        }
    }
};
