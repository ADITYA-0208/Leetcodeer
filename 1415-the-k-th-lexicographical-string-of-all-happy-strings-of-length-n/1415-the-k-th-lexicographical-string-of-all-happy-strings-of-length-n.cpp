class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> vec;
        string s = "";
        char last = 'd';  
        fucc(s, vec, n, last);

        if (k <= vec.size()) {
            return vec[k - 1];
        }
        return ""; 
    }

    bool happy(string s, int n) {
        if (s.size() != n) return false;
        char prev = 'd';
        for (auto ch : s) {
            if (ch == prev) return false;
            prev = ch;
        }
        return true;
    }

    void fucc(string s, vector<string> &vec, int n, char last) {
        if (s.size() == n) {
            if (happy(s, n)) {
                vec.push_back(s);
            }
            return;
        }
        if (last != 'a') fucc(s + 'a', vec, n, 'a');
        if (last != 'b') fucc(s + 'b', vec, n, 'b');
        if (last != 'c') fucc(s + 'c', vec, n, 'c');
    }
};
