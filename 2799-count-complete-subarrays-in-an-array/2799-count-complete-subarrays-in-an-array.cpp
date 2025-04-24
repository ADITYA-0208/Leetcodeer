class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int>map1;
        for(int i=0;i<nums.size();i++){
            map1[nums[i]]++;
        }
        int n=nums.size();
        unordered_map<int,int>hash;
        int l=0,r=0,count=map1.size(),ans=0;
        while(l<=r && r<n){
            hash[nums[r]]++;
            while(count==hash.size()){
                ans+=n-r;
                hash[nums[l]]--;
                if(hash[nums[l]]==0)  hash.erase(nums[l]);
                l++;
            }
            r++;
            
        }
        return ans;
    }
};