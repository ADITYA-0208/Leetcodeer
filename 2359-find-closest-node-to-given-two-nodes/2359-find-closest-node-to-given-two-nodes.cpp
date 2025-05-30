class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        
        vector<int>dist1(n,1e9),dist2(n,1e9);
        dist1=bfsShortestPath(n,edges,node1);
        dist2=bfsShortestPath(n,edges,node2);
        int ans = -1, minDist = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (dist1[i] != 1e9 && dist2[i] != 1e9) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    ans = i;
                }
            }
        }
        return ans;
    }
    vector<int> bfsShortestPath(int n, vector<int> &edges, int src) {
        vector<int> dist(n, 1e9);
        vector<bool> visited(n, false);
        queue<int> q;

        dist[src] = 0;
        visited[src] = true;
        q.push(src);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            int v = edges[u];
            if (v != -1 && !visited[v]) {
                dist[v] = dist[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
        return dist;
    }
};