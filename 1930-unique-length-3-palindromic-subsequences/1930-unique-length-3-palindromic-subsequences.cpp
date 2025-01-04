class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<char>> ans; 
        vector<char> p; 
        generateSubsets(ans, p, s, 0);
        sort(ans.begin(), ans.end());
        auto it = unique(ans.begin(), ans.end());
        ans.erase(it, ans.end());
        return ans.size();
    }

    void generateSubsets(vector<vector<char>>& ans, vector<char>& p, string& s, int i) {
        if (p.size() == 3 && p[0] == p[2]) { 
            ans.push_back(p);
            return;
        }

        if (i >= s.size() ) { 
            return;
        }
        p.push_back(s[i]);
        generateSubsets(ans, p, s, i + 1);
        p.pop_back();
        generateSubsets(ans, p, s, i + 1);
    }
};
