class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
         vector<int>rightmax(n,-1);
        rightmax[n-1]=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i+1]<nums[i])   rightmax[i]=rightmax[i+1];
            else if(nums[i+1]>nums[i])    rightmax[i]=nums[i+1];
        }

        int maxi=-1;
        vector<int>ans(n,-1);
        for(int i=0;i<nums.size();i++){
            if(rightmax[i]==-1 && maxi>nums[i]){
                ans[i]=maxi;
            }
            else{
                ans[i]=rightmax[i];
            }
            maxi=max(maxi,nums[i]);
        }
        return ans;
    }
};