class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),j=0,k=0;
        vector<vector<int>>ans;
        vector<int>ans2;
        for(int i =0;i<nums.size()-1;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            j=i+1;
            k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;

                }
                else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        for (auto &v:ans) {
            sort(v.begin(), v.end());
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};