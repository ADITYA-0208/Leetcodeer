class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>map1;
        for(int i=0;i<nums.size();i++){
            map1[nums[i]].push_back(i);
        }
        int count=0;
        for(auto& [it,vec] :map1){
            for(int i=0;i<vec.size();i++){
                for(int j=i+1;j<vec.size();j++){
                    if(vec[i]*vec[j]%k==0)  count++;
                }
            }
        }
        return count;
    }
};