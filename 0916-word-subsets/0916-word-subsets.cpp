class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> word2total;
        for (auto it : words2) {
            unordered_map<char, int> word2map;
            for (auto c : it)
                word2map[c]++;
            for (auto& pair : word2map) {
                word2total[pair.first] =
                    max(word2total[pair.first], pair.second);
            }
        }

        vector<string> result;
        for (auto it : words1) {
            unordered_map<char, int> freq;
            for (char c : it)
                freq[c]++;
            bool flag = true;
            for (auto& pair : word2total) {
                if (freq[pair.first] < pair.second) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                result.push_back(it);
        }

        return result;
    }
};
