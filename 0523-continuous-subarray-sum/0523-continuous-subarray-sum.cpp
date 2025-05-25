class Solution {
public:
//brute
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix(n+1,0);
        unordered_map<int,int>map1;
        for(int i=0;i<n;i++)    prefix[i+1]=prefix[i]+nums[i];
        for(int i=0;i<n+1;i++)    prefix[i]=prefix[i]%k;
        for(int i=0;i<n+1;i++){
            if(map1.find(prefix[i])==map1.end()){
                map1[prefix[i]]=i;
            }
            else{
                if(abs(map1[prefix[i]]-i)>=2){
                    return true;
                }
            }
        }
        return false;
    }
};