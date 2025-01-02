class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<char>> visited(n, vector<char>(m, 0));
        int total=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1)&&grid[i][j]==1){   q.push({i,j});visited[i][j]=1;}
                if(grid[i][j]==1)    total++;
            }
        }
        int k=q.size();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            pair<int,int> top=q.front();
            int i=top.first;
            int  j=top.second;
            q.pop();
            for (auto [di, dj] : directions) {
                int ni = i + di;
                int nj = j + dj;
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1 && !visited[ni][nj]) {
                    cout<<"I"<<ni<<"j"<<nj<<"   ";
                    q.push({ni, nj});
                    visited[ni][nj] = 1; 
                    k++;
                }
            }
        }
        int ans=abs(total-k);
         return ans;
    }
};