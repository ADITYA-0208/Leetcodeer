class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topsum= accumulate(begin(grid[0]), end(grid[0]), 0LL); //O(col)
        long long bottomsum= 0;
        long long mini = LONG_LONG_MAX;

        for(int i=0;i< grid[0].size();i++) { 
            topsum -= grid[0][i];
            long long best= max(topsum, bottomsum);
            mini= min(mini,best);
            bottomsum+= grid[1][i];
        }
        return mini;
    }
};