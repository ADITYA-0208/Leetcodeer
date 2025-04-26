class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int j=0,k=0;
        vector<vector<int>>ans;
        for(int i=0;i<n-3;i++){
            for (int l=n-1;l>i+2;l--){
                j=i+1;
                k=l-1;
                int sum=nums[i]+nums[l];
                while(j<k){
                    if(sum+nums[j]+nums[k]>target){
                        k--;
                    }
                    else if(sum+nums[j]+nums[k]<target){
                        j++;
                    }
                    else{
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        j++;
                        k--;
                    }
                }
            }
        }
        for(auto& v : ans){
            sort(v.begin(),v.end());
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};