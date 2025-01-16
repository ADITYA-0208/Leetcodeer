class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
       int n = roads.size() + 1;
        vector<vector<int>> grid(n);
        for(auto road : roads){
            grid[road[0]].push_back(road[1]);
            grid[road[1]].push_back(road[0]);
        }
        queue<pair<int,int>>q;
        vector<bool> visited(n, false);
         visited[0]=true;
        q.push({0,1});
        long long total=0;
        while(!q.empty()){
            auto it =q.front();
            q.pop();
            for(auto neighbour:grid[it.first]){
                if(visited[neighbour]==false){
                    visited[neighbour]=true;
                    int newc=1;
                    if(it.second%seats==0)   newc=it.second/seats;
                    if(it.second%seats!=0)  newc=(it.second+seats-1)/seats;
                    total+=newc;
                    q.push({neighbour,it.second+1});}
            }}
            
        return total;
    }
};