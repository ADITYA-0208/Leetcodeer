class Solution {
public:
    struct hash_pair {
        size_t operator()(const pair<int, vector<int>>& p) const {
            size_t hash1 = hash<int>()(p.first);
            size_t hash2 = 0;
            for (int val : p.second) {
                hash2 ^= hash<int>()(val) + 0x9e3779b9 + (hash2 << 6) + (hash2 >> 2);
            }
            return hash1 ^ hash2;
        }
    };
    int find1(int val,vector<int>&visited,int n,unordered_map<pair<int,vector<int>>,int,hash_pair>&mp){
        if(val>n)   return 1;
        int ans=0;
        if(mp.count({val,visited})!=0)  return mp[{val,visited}];
        for(int i=1;i<=n;i++){
            if(visited[i-1]==0 && (val%i==0 || i%val==0)){
                visited[i-1]=1;
                ans+=find1(val+1,visited,n,mp);
                visited[i-1]=0;
            }
        }

        mp[{val,visited}]=ans;
        return ans;
    }
    int countArrangement(int n) {
        unordered_map<pair<int,vector<int>>,int,hash_pair>mp;
        vector<int>visited(n,0);
        return find1(1,visited,n,mp);
    }
};