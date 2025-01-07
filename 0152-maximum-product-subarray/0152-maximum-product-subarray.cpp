class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int maxi = nums[0];
        for (int i = 0; i < n; i++) {
            int mul = nums[i];
            maxi = max(maxi, mul);
            for (int j = i + 1; j < n; j++) {
                mul = mul * nums[j];
                if(mul<0 && maxi>0) {i=j+1; break;}
                maxi = max(maxi, mul);
            }
        }
        return maxi;
    }
};
