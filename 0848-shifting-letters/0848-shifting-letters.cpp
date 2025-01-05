class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> delta(n + 1, 0);

        for (const auto& shift : shifts) {
            int x = shift[0], y = shift[1], d = shift[2];
            delta[x] += (d == 1) ? 1 : -1;
            delta[y + 1] -= (d == 1) ? 1 : -1;
        }

        int currentShift = 0;
        for (int i = 0; i < n; i++) {
            currentShift += delta[i];
            int shift = (s[i] - 'a' + currentShift) % 26;
            if (shift < 0) shift += 26;
            s[i] = 'a' + shift;
        }

        return s;
    }
};
