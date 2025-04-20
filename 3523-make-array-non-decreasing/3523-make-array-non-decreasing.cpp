class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(maxi<=nums[i])   { maxi=nums[i];count++;}
        }
        return count;
    }
};