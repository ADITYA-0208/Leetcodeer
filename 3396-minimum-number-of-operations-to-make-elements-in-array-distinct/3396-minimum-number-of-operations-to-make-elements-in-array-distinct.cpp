class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i+=3){
            unordered_set<int> seen;
            bool isUnique = true;
            for(int j=i;j<n;j++){
                if(seen.count(nums[j])) {
                    isUnique = false;
                    break;
                }
                seen.insert(nums[j]);
            }
            if(isUnique) return i/3;
        }
        return (n + 2) / 3; 
       }
};
