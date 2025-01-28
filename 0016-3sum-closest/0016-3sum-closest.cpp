class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sum=nums[0]+nums[1]+nums[2];
        if(nums.size()==3)    return sum;
        int mini=1e9;
        int ans;
        for(int k=0;k<nums.size();k++){
        int i=k+1;

        int j=nums.size()-1;
        while(i<j){
            int sum=nums[k]+nums[i]+nums[j];
            if(mini>abs(sum-target)){
                ans=sum;
                mini=abs(sum-target);
            }
            if(sum<target)  i++;
            else j--;
        }}
        return ans;
    }
};