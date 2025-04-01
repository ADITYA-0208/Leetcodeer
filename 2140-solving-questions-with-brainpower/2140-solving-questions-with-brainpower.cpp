class Solution {
public:
    long long fucc(vector<vector<int>>& questions,vector<long long> &dp,int pos){
        if(pos>=questions.size()){
            return 0;
        }
        if(dp[pos]!=-1)  return dp[pos];

        long long not1=fucc(questions,dp,pos+1);
        long long yes=questions[pos][0]+fucc(questions,dp,pos+questions[pos][1]+1);

        return dp[pos]=max(not1,yes);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n,-1);
        return fucc(questions,dp,0);
    }
};