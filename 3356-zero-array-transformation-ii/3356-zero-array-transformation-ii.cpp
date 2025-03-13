class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);  
        int k = 0; 
        int sum = 0; 
        
        for (int i = 0; i < n; i++) {
            while (sum + diff[i] < nums[i]) { 
                if (k == queries.size()) return -1; 
                int l = queries[k][0], r = queries[k][1], val = queries[k][2];
                k++; 
                if(r<i) continue;
                diff[max(l,i)] += val;
                if (r + 1 < n) diff[r + 1] -= val;
            }
            sum += diff[i]; 
        }
        return k; 
    }
};
