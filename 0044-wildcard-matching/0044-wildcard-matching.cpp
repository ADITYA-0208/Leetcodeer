class Solution {
public:
    bool fucc(int i,int j, string s ,string p, vector<vector<int>>dp){
        //j for p
        //i for s
        if(i==0 && j==0)    return true;
        if(i==0 && j>0)     return false;
        if(i>0 && j==0){
            for(int k=0;k<=i;k++){
                if(p[i-1]!='*') return false;
            }
            return true;
        }
        if(s[j-1]==p[i-1] && p[i-1]=='?'){
            return fucc(i-1,j-1,s,p,dp);
        }
        if(p[i-1]=='*'){
            if(fucc(i-1,j,s,p,dp) || fucc(i,j-1,s,p,dp))    return true;
            return false;
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return fucc(m,n,s,p,dp);
    }
};