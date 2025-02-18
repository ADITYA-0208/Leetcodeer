class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> p;
        vector<int> y;
        fucc(1, p, y, n, k);
        return p;
    }

    void fucc(int ind, vector<vector<int>>& p, vector<int>& y, int n, int k) {
        if (y.size() == k) {
            p.push_back(y);
            return;
        }
        if (ind > n) return;  

        fucc(ind + 1, p, y, n, k);  
        y.push_back(ind);           
        fucc(ind + 1, p, y, n, k);
        y.pop_back();                
    }
};
