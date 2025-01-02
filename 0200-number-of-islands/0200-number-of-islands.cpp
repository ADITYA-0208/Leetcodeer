class Solution {
public:
    void bfs(vector<vector<char>>& grid,vector<vector<char>>& visited,int row,int col,int n,int m ){
        queue<pair<int ,int>>q;
        q.push({row,col});
        while(!q.empty()){
            pair<int,int> top;
            top=q.front();
            q.pop();
            int i=top.first;
            int j=top.second;
            visited[i][j]=1;
            if(i-1>=0 &&grid[i-1][j]=='1' && visited[i-1][j]==0)   q.push({i-1,j});
            if(j-1>=0 &&grid[i][j-1]=='1' && visited[i][j-1]==0)   q.push({i,j-1});
            if(i+1<n &&grid[i+1][j]=='1' && visited[i+1][j]==0)   q.push({i+1,j});
            if(j+1<m &&grid[i][j+1]=='1' && visited[i][j+1]==0)   q.push({i,j+1});

        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<char>> visited(n,vector<char>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    cnt++;
                    bfs(grid,visited,i,j,n,m);
                }
            }
        }
        return cnt;
    }
};