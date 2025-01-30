class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> globalVisited(n + 1, 0); 
        int mx = 0;

        for (int i = 1; i <= n; i++) {
            if (!globalVisited[i]) {
                vector<int> component;
                if (!isBipartite(i, graph, globalVisited, component)) return -1;
                int maxLevels = 0;
                for (int node : component) {
                    vector<int> visited(n + 1, 0);
                    maxLevels = max(maxLevels, levels(graph, node, visited));
                }

                mx += maxLevels;
            }
        }
        return mx;
    }

    bool isBipartite(int start, vector<vector<int>>& graph, vector<int>& globalVisited, vector<int>& component) {
        queue<int> q;
        vector<int> color(graph.size(), -1);
        
        q.push(start);
        color[start] = 0;
        globalVisited[start] = 1;
        component.push_back(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                if (color[v] == -1) { 
                    color[v] = 1 - color[u];  
                    globalVisited[v] = 1;
                    q.push(v);
                    component.push_back(v);
                } else if (color[v] == color[u]) {
                    return false; 
                }
            }
        }
        return true;
    }

    int levels(vector<vector<int>>& graph, int start, vector<int> &visited) {
        queue<int> q;
        int total = 0;
        q.push(start);
        visited[start] = 1;
        
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
        return total;  
    }
};
