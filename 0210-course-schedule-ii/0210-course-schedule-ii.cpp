class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0); 
        stack<int> ans;                    
        vector<vector<int>> adjList(numCourses); 
        
        for (auto& prereq : prerequisites) {
            adjList[prereq[1]].push_back(prereq[0]);
        }

        
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (!dfs(i, ans, adjList, visited)) {
                    return {}; 
                }
            }
        }

        vector<int> result;
        while (!ans.empty()) {
            result.push_back(ans.top());
            ans.pop();
        }

        return result;
    }

       bool dfs(int node, stack<int>& st, vector<vector<int>>& adjList, vector<int>& visited) {
        visited[node] = 1;


        for (int neighbor : adjList[node]) {
            if (visited[neighbor] == 1) {
                return false;             }
            if (visited[neighbor] == 0) {
                if (!dfs(neighbor, st, adjList, visited)) {
                    return false;                 }
            }
        }

        visited[node] = 2;  
        st.push(node);              return true;            }
};
