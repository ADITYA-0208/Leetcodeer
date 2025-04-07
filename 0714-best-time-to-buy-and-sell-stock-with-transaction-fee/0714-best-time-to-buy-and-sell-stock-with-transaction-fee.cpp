class Solution {
public:
    int fucc(int i, int buy, vector<int>& prices,int fee) {
        if (i == prices.size()) return 0;
        int pro = 0;
        if (buy == 1)
            pro = max(-prices[i] + fucc(i + 1, 0, prices,fee), fucc(i + 1, 1, prices,fee));
        else
            pro = max(prices[i] -fee+ fucc(i + 1, 1, prices,fee), fucc(i + 1, 0, prices,fee));
        return pro;
    }
    int maxProfit(vector<int>& prices, int fee) {
        
        return fucc(0,1,prices,fee);
    }
};