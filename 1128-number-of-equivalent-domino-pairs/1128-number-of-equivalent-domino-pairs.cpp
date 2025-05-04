class Solution {
public:
    struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first * 31 + p.second);
    }
};
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count=0;
        unordered_map<pair<int, int>, int, pair_hash> map1;
        for(auto it :dominoes){
            int a=it[0];
            int b=it[1];
            if(a<=b){
                pair<int,int>check={a,b};
                int c=map1[check];
                count+=c;
                map1[check]++;
            }
            if(b<a){
                pair<int,int>check={b,a};
                int c=map1[check];
                count+=c;
                map1[check]++;
            }
        }
        return count;
    }
};