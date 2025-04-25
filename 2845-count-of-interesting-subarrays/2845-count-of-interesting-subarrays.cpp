class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n=nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]%modulo==k)   ans[i]=1;
        }
        
        long long res=0;
        int cur = 0;
        unordered_map<int, int> prefix;
        prefix[0]=1;
        for (int i = 0; i < nums.size(); i++){
            cur += ans[i];
            if(cur % modulo == k && prefix.find((cur-k+modulo)%modulo) == prefix.end())
                res++;
            if(prefix.find((cur-k+modulo)%modulo) != prefix.end())
                res += prefix[(cur-k+modulo)%modulo];
            prefix[cur% modulo]++;
        }

        return res;
    }
};