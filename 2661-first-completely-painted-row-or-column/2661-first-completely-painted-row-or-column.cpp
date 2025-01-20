class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int, int>> vec(n * m + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vec[mat[i][j]] = {i, j};
            }
        }
        vector<int> row(n, 0);
        vector<int> col(m, 0);
        for (int i = 0; i < arr.size(); i++) {
            int x = vec[arr[i]].first;  
            int y = vec[arr[i]].second;

            row[x]++;
            if (row[x] == m) return i;

            col[y]++;
            if (col[y] == n) return i; 
        }

        return -1;
    }
};
