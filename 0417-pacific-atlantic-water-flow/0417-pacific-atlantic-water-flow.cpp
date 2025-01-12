class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int,int>> pac,atl;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>>paci(n,vector<bool>(n,false));
        vector<vector<bool>>atla(n,vector<bool>(m,false));
        for (int i = 0; i < n; i++) {
            pac.push({i,0});
            atl.push({i,m-1});
            paci[i][0]=true;
            atla[i][m-1]=true;
        }
        for (int j = 0; j < m; j++) {
            pac.push({0,j});
            atl.push({n-1,j});
            paci[0][j]=true;
            atla[n-1][j]=true;
        }
            bfs(heights,pac,paci);
            bfs(heights,atl,atla);
            vector<vector<int>>result;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(paci[i][j] && atla[i][j]){
                        result.push_back({i,j});
                    }
                }
            }
            return result;
    }
    void bfs(vector<vector<int>>& heights,queue<pair<int,int>>q,vector<vector<bool>>&visited){
       
        int n=heights.size();
        int m=heights[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int i = top.first;
            int j = top.second;
            visited[i][j]=true;
            for(auto [di,dj]:directions){
                int ni= i+di;
                int nj=j+dj;
                if (ni >= 0 && ni < n && nj >= 0 && nj < m &&visited[ni][nj]==false && heights[ni][nj] >= heights[i][j]) {
                    q.push({ni,nj});

                }
            }
        }
    }
};
