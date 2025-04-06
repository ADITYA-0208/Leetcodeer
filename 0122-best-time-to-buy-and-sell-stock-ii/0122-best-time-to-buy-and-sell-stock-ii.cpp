class Solution {
public:
    int fucc(int i,int buy,vector<int>&prices){
        if(i==prices.size())    return 0;
        long long pro=0;
        if(buy==1)  pro=max(-prices[i]+fucc(i+1,0,prices),fucc(i+1,1,prices));
        if(buy==0)  pro=max(prices[i]+fucc(i+1,1,prices),fucc(i+1,0,prices));

        return (int)pro;
    }
    int maxProfit(vector<int>& prices) {
        return fucc(0,1,prices);
    }
};