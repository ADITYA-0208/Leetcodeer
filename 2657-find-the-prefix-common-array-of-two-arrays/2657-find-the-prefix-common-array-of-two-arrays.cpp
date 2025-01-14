class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> c(n, 0);
        vector<bool> vis(n + 1, false); 
        int k = 0;
        
        for (int i = 0; i < n; i++) {
            if (vis[A[i]]) k++;
            vis[A[i]] = true;

            if (seen[B[i]]) k++;
            seen[B[i]] = true;

            c[i] = k;
        }
        
        return c;
    }
};
