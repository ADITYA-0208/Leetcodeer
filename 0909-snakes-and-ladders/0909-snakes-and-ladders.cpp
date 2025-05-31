class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,1});
        int n=board.size();
        vector<bool>visited(n*n+1,false);
        while(!pq.empty()){
            auto [k,i] =pq.top();
            pq.pop();
            if(visited[i])  continue;
            visited[i]=true;
            if(i==n*n)  return k;

            for(int d=1;d<=6 && i+d <= n*n;d++){
                int next = i + d;
                int r=(next-1)/n;
                int c=(next-1)%n;
                if (r % 2 == 1) c = n - 1 - c; // handle zigzag
                int dest;
                if(board[n-r-1][c]==-1)    dest=next;
                else    dest=board[n-r-1][c];
                if(!visited[dest])  pq.push({k+1,dest});
            }
        }
        return -1;
    }
};