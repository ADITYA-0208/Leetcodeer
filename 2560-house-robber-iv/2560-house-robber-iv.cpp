class Solution {
public:
    bool cheaks(vector<int>& nums,int k,int mid){
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid) {count++;i++;}
        }
        return count>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int l=*min_element(nums.begin(), nums.end());
        int r=*max_element(nums.begin(), nums.end());
        int ans;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(cheaks(nums,k,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};