class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> map1;
        unordered_map<char, string> map2; 
        string p = "";
        int t = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (t >= pattern.size()) return false; 
                if (map1.find(p) != map1.end()) {
                    if (map1[p] != pattern[t]) return false;
                } 
                else {
                    if (map2.find(pattern[t]) != map2.end() && map2[pattern[t]] != p) return false;
                    map1[p] = pattern[t];
                    map2[pattern[t]] = p;
                }
                p = "";
                t++;
            } 
            else    p += s[i];  
        }

        if (t >= pattern.size()) return false; 
        if (map1.find(p) != map1.end()) {
            if (map1[p] != pattern[t]) return false;
        } 
        else {
            if (map2.find(pattern[t]) != map2.end() && map2[pattern[t]] != p) return false;
            map1[p] = pattern[t];
            map2[pattern[t]] = p;
        }

        return t + 1 == pattern.size(); // Ensure word count matches pattern length
    }
};
