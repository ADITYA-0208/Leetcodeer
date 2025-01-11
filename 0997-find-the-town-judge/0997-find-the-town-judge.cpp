class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>ans(n+1,0);
        if(n==1)    return 1;
        for(int i=0;i<trust.size();i++){
                ans[trust[i][1]]++;
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]==n-1){
                 for(int j=0;j<trust.size();j++){
                    if(trust[j][0]==i)  return -1;  
                 }
                 return i;
            }
        }
        return -1;
    }
};