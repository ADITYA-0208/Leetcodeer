class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int maxlen = 0, start = 0,maxi=0;
        for (int i = 0; i <= nums.size(); i++) {
            if (i == nums.size() || nums[i] == 0) {
            if (start < i) fucc(vector<int>(nums.begin() + start, nums.begin() + i), 0, maxlen);
                start = i + 1; 
                maxi=max(maxi,maxlen);
            }
        }
        return maxi;
    }

    void fucc(vector<int> nums, int negcount, int& maxlen) {
        int n = nums.size();
        int firstneg = -1, lastneg = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                negcount++;
                if (firstneg == -1) firstneg = i;
                lastneg = i;
            }
        }
        if (negcount % 2 == 0) maxlen = max(maxlen, n);
        else maxlen = max(maxlen, max(n - firstneg - 1, lastneg));
    }
};
