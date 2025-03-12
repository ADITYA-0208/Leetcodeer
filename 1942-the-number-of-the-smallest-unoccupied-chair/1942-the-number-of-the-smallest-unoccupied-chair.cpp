class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        for(int i=0;i<times.size();i++){
            times[i].push_back(i);
        }
        int targetArrival = times[targetFriend][0];
        sort(times.begin(),times.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        priority_queue<int, vector<int>, greater<int>> aval;
        int nextchair=0;
        for(int i=0;i<times.size();i++){
            while(!pq.empty() && times[i][0]>=pq.top().first){
                aval.push(pq.top().second);
                pq.pop();
            }
            int assign;
            if (!aval.empty()) {
                assign = aval.top();
                aval.pop();
            } 
            else    assign = nextchair++;
            pq.push({times[i][1], assign});
            if (times[i][0] == targetArrival) return assign;
        }
        return -1;
    }
};