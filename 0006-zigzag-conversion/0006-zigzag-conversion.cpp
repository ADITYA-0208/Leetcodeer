class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows) return s;

        bool flag = true;
        vector<string> row(numRows, "");
        int k = 0;

        for (int i = 0; i < s.size(); i++) {
            if (flag) {
                row[k] += s[i];
                k++;
                if (k == numRows) {
                    flag = false;
                    k = numRows - 2;
                }
            } else {
                row[k] += s[i];
                k--;
                if (k < 0) {
                    flag = true;
                    k = 1;
                }
            }
        }

        string result;
        for (string rows : row) {
            result += rows;
        }
        return result;
    }
};
