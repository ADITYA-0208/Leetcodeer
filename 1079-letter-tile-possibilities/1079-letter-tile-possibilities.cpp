class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> map1;
        unordered_map<char, int> freq;
        for (char ch : tiles) {
            freq[ch]++;  
        }
        recc(freq, "", map1);
        return map1.size();  
    }

    void recc(unordered_map<char, int>& freq, string s, unordered_set<string>& map1) {
        if (!s.empty()) {
            map1.insert(s);  
        }

        for (auto& [ch, f] : freq) {
            if (f > 0) {
                freq[ch]--; 
                recc(freq, s + ch, map1);  
                freq[ch]++;  
            }
        }
    }
};