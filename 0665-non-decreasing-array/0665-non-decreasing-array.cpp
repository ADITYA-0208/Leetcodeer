class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool flag=false;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1] && flag==true)   return false;
            if(nums[i]>nums[i+1] && flag==false)    flag=true;
        }
        return true;
    }
};