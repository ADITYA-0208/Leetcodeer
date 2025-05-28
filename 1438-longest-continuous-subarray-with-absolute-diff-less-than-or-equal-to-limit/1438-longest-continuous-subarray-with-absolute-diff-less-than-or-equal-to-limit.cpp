class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxi,mini;
        int res=0;
        int l=0,n=nums.size();
        for(int r=0;r<n;r++){
            while(!maxi.empty() && nums[r]>maxi.back()){
                maxi.pop_back();
            }
            while(!mini.empty() && nums[r]<mini.back()){
                mini.pop_back();
            }

            maxi.push_back(nums[r]);
            mini.push_back(nums[r]);

            while(maxi.front()-mini.front()>limit){
                if(nums[l]==maxi.front())   maxi.pop_front();;
                if(nums[l]==mini.front())   mini.pop_front();
                l++;
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};