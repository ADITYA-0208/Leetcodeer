class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int n=nums.size();
        int h=n-1;
            if (n == 1) return nums[0];
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if((nums[mid]==nums[mid-1] && mid%2==1) || (nums[mid]==nums[mid+1] && mid%2==0)){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
    return -1;
    }
};