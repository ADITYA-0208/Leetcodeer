class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int>hash1;
        int l=0,r=0,pair=0,count=0,n=nums.size();
        for(int r=0;r<n;r++){
            if(hash1.count(nums[r]))  {pair+=hash1[nums[r]];}
            hash1[nums[r]]++;
            while(pair>=k){
                count+=n-r;
                hash1[nums[l]]--;
                pair-=hash1[nums[l]];
                l++;
            }
        }
        return count;
    }
};