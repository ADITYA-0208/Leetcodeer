class Solution {
public:
     int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>lefts(n);
        vector<int>rights(n);
        stack<int>st1;
        for(int i=0;i<n;i++){
            while(!st1.empty() && heights[st1.top()]>= heights[i]){
                st1.pop();
            }
            if(st1.empty())  lefts[i]=0;
            else    lefts[i]=st1.top()+1;
            st1.push(i);
        }
        stack<int>st2;
        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && heights[st2.top()]>= heights[i]){
                st2.pop();
            }
            if(st2.empty())  rights[i]=n-1;
            else    rights[i]=st2.top()-1;
            st2.push(i);
        }
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, heights[i] * (rights[i] - lefts[i] + 1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) ans[i][j] = matrix[i][j] - '0';
                else ans[i][j] = (matrix[i][j] == '1') ? ans[i - 1][j] + 1 : 0;
            }
        }
        int maxi=INT_MIN;
        for(int i=0;i<ans.size();i++){
            maxi=max(maxi,largestRectangleArea(ans[i]));
        }
        return maxi;
    }
};