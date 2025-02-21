class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int size1 = 0;
        
        for (int i = 0; i < n; i++) {
            int zcount = 0, ocount = 0;
            
            for (int j = i; j < n; j++) {
                if (nums[j] == 0) zcount++;
                if (nums[j] == 1) ocount++;
                
                if (zcount == ocount) {
                    size1 = max(size1, j - i + 1);
                }
            }
        }
        return size1; 
    }
};
