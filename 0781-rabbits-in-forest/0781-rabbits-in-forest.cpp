class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> map;
        int n = answers.size();
        for(int i = 0; i < n; i++) {
            if(answers[i] == 0) continue;
            map[answers[i]]++;
        }
        int ans = 0;
        
        while(map.size()!=0){
            unordered_set<int>set1;
            for(auto [it,count]:map)
                set1.insert(it);
            for(int it: set1){
                int count=map[it];
                if(it + 1 >=count || count%(it+1)==0) {
                    if(it + 1 >=count){
                    ans += it + 1 - count;
                    map.erase(it);}
                    if(it+1<count){
                        map.erase(it);
                    }
                    cout<<ans;
                } 
                else{
                    ans += (count%(it+1))* it;
                    map[it] -= count%(it+1);
                    cout<<ans<<". /. ";
                }
            }
        }
        return ans + n;
    }
};
    