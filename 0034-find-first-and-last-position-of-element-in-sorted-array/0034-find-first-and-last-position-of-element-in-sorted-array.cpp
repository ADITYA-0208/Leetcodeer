class Solution {
public:
    int firstind(vector<int>& nums, int target){
        int low=0;int high=nums.size()-1;
        int first=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                high=mid-1;
                first=mid;
            }
            if(nums[mid]>target){
                first=mid;
                high=mid=1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
        }
        return first;
    }
    int lastind(vector<int>& nums, int target){
        int low=0;int high=nums.size()-1;
        int first=1e9;int last=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                low=mid+1;
               last=mid;
            }
            if(nums[mid]>target){
                first=mid;
                high=mid=1;
            }
            else {
                low=mid+1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int x=firstind(nums,target);
        if(x==-1)   return {-1,-1};
        int y=lastind(nums,target);
        return {x,y};
    }
    
};