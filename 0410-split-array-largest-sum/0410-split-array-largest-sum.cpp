class Solution {
public:
    bool fucc(vector<int>& nums, int k,int tar){
        int p=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<tar){
                 sum+=nums[i];
            }
            else{
               p++;
               sum=0;
            }
            if(p>k)    return true;
        }
         return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=0;
        if(nums.size()==k)  return low;
        for(int i=0;i<nums.size();i++){
            high+=nums[i];
        }
        int y=high;
        int result=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(fucc(nums,k,mid)){
                low=mid+1;
                result=mid;
            }
            else    high=mid-1;
        }
        return max(result,y-result);
    }
};