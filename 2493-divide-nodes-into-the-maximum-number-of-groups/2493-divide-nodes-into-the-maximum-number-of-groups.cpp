class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        if (!isBipartite(n, graph)) return -1;

        vector<int> visited(n + 1, 0);
        int mx = 0;

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                mx = max(mx, levels(graph, i, visited));
            }
        }
        return mx;
    }

    int levels(vector<vector<int>>& graph, int i, vector<int> &visited) {
        queue<int> q;
        int total = 0;
        q.push(i);
        visited[i] = 1;
        
        while (!q.empty()) {
            int size = q.size();
            for (int z = 0; z < size; z++) {
                int k = q.front();
                q.pop();
                for (auto it : graph[k]) {
                    if (!visited[it]) {
                        visited[it] = 1;  
                        q.push(it);
                    }
                }
            }
            total++;
        }
        return total+1;
    }

    bool isBipartite(int V, vector<vector<int>> &adj) {
        vector<int> color(V + 1, -1);
        queue<int> q;
        
        for (int i = 1; i <= V; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                q.push(i);
                
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    
                    for (auto &v : adj[u]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
