class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int target = sum / k;
        sort(nums.rbegin(), nums.rend());
        vector<int> subset(k, 0);

        return fucc(nums, subset, 0, k, 0, target);
    }
    
    bool fucc(vector<int>& nums, vector<int>& subset, int j, int k, int ind, int target) {
        if(ind == nums.size()) {
            for(int i=0; i<subset.size();i++) {
                if(subset[i]!=target) return false;
            }
            return true;
        }
        for(int i=0;i<subset.size();i++) {
            if(subset[i]+nums[ind]>target) continue;
            subset[i]+=nums[ind];
            if(fucc(nums,subset,j+1,k,ind+1,target)) return true;
            subset[i] -= nums[ind];
            if(subset[i]==0) break;
        }
        return false;
    }
};
