class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>map1;
        for(int i=0;i<nums.size();i++){
            if(map1.find(nums[i])==map1.end()) map1[nums[i]]=1;
            else    map1[nums[i]]++;
        }
        for(auto [it,cnt]:map1){
            if(cnt%2!=0)    return false;
        }
        return true;
    }
};