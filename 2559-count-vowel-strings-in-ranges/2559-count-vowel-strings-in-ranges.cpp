class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> count;
        for (int it = 0; it < words.size(); it++) {
            char fi = words[it][0];
            int n = words[it].size();
            char sc = words[it][n - 1];
            if ((fi == 'a' || fi == 'e' || fi == 'i' || fi == 'o' || fi == 'u') &&
                (sc == 'a' || sc == 'e' || sc == 'i' || sc == 'o' || sc == 'u')) {
                count.push_back(1);
            } else {
                count.push_back(0);
            }
        }
        
        vector<int> ans(queries.size(), 0); 
        
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + count[i];
        }
        for (const auto& query : queries) {
            int s = query[0];
            int l = query[1];
            ans.push_back(prefixSum[l + 1] - prefixSum[s]);
        }
        return ans;
    }
};
