class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<P, vector<P>, greater<P>> pq; 
        int m=nums2.size();
        int sum=nums1[0]+nums2[0];
        int n=nums1.size();
        pq.push({sum,{0,0}});
        set<pair<int, int>> visited;
        visited.insert({0, 0});
        vector<vector<int>>ans;
        while(!pq.empty() && k--){
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            ans.push_back({nums1[x],nums2[y]});
            pq.pop();
            if(y+1<m  && visited.find({x,y+1})==visited.end()){
                pq.push({nums1[x]+nums2[y+1],{x,y+1}});
                visited.insert({x, y + 1});
            }
            if(x+1<n && visited.find({x+1,y})==visited.end() ){
                pq.push({nums1[x+1]+nums2[y],{x+1,y}});
                visited.insert({x+1,y});
            }
        }
        return ans;
    }
};