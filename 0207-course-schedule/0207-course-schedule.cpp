class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> arr[numCourses];
        vector<int> visited(numCourses,0);
        for(auto i :prerequisites){
            arr[i[1]].push_back(i[0]);
            visited[i[0]]++;
        }
        queue<int> q;
        for(int j=0;j<numCourses;j++){
            if(visited[j] == 0)
                q.push(j);
        }
        vector<int> top;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            top.push_back(it);
            for(auto node:arr[it]){
                visited[node]--;
                if(visited[node] == 0)
                    q.push(node);
            }
        }
        if(top.size() == numCourses)
            return true;
        return false;


    }
};