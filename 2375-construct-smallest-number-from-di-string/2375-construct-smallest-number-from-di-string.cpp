class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string ans = "";
        
        for (int i = 0; i <= n; i++) {
            ans += (char)('1' + i);
        }
        int i = 0;
        while (i < n) {
            if (pattern[i] == 'D') {
                int j = i;
                while (j < n && pattern[j] == 'D') {
                    j++;
                }
                reverse(ans.begin() + i, ans.begin() + j + 1); 
                i = j;
            }
            i++;
        }
        
        return ans;
    }
};
