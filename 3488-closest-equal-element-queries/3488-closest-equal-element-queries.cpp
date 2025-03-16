class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> map1;
        for (int i = 0; i < nums.size(); i++) {
            map1[nums[i]].push_back(i);
        }
        
        int n = nums.size();
        int m = queries.size();
        vector<int> result(m, -1);

        for (int i = 0; i < queries.size(); i++) {
            int p = nums[queries[i]];
            if (map1[p].size() == 1) continue;

            auto& vec = map1[p];
            int s = vec.size();
            auto it = lower_bound(vec.begin(), vec.end(), queries[i]);
            int ind = (it == vec.end()) ? s - 1 : it - vec.begin();
            
            int mini = INT_MAX;
            if (ind > 0) mini = min(mini, abs(vec[ind - 1] - queries[i]));
            if (ind < s - 1) mini = min(mini, abs(vec[ind + 1] - queries[i]));
            mini = min(mini, n - abs(vec[0] - queries[i]));
            mini = min(mini, n - abs(vec[s - 1] - queries[i]));

            result[i] = mini;
        }
        return result;
    }
};
