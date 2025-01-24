class Solution {
public:
    bool fucc(vector<int>nums,int &mid,int& threshold){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]+mid-1)/mid;
        }
        if(sum<=threshold)  return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int high = *max_element(nums.begin(), nums.end());
        int low=1;
        while(low<=high){
            int mid=(low+high)/2;
            if(fucc(nums,mid,threshold)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};