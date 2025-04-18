class Solution {
public:
    int beauty(unordered_map<int,int>hash1){
        int mini=INT_MAX;
        int maxi=0;
        for(auto [it,count]: hash1){
            mini=min(mini,count);
            maxi=max(maxi,count);
        }
        return maxi-mini;
    }
    int beautySum(string s) {
        int n = s.size();
        vector<vector<int>> prefix(n + 1, vector<int>(26, 0));
        int total = 0;

        // Build prefix frequency array
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i];  // copy previous
            prefix[i + 1][s[i] - 'a']++;
        }

        // Check all substrings
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vector<int> freq(26);
                for (int ch = 0; ch < 26; ch++) {
                    freq[ch] = prefix[j + 1][ch] - prefix[i][ch];
                }

                int maxFreq = 0, minFreq = INT_MAX;
                for (int f : freq) {
                    if (f > 0) {
                        maxFreq = max(maxFreq, f);
                        minFreq = min(minFreq, f);
                    }
                }

                total += maxFreq - minFreq;
            }
        }

        return total;
    }
};