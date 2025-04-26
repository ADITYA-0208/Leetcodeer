class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int ind1=-1;
        int ind2=-1;
        int inval=-1;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxK  || nums[i]<minK){
                inval=i;ind1=-1;ind2=-1;
            }
            if(nums[i]==minK)   ind1=i;
            if(nums[i]==maxK)   ind2=i;
            if(min(ind1,ind2)-inval>0){
                ans+=min(ind1,ind2)-inval;
            }
        }
        return ans;
    }
};