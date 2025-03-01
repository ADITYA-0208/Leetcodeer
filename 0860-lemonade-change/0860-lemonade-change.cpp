class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> coin(3,0);
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5)     coin[0]++;
            if(bills[i]==10){
                if(coin[0]<1)  return false;
                coin[0]--;
                coin[1]++; 
            }
            if(bills[i]==20){
                if(coin[0]<1 || coin[1]<1 )  return false;
                coin[0]--;
                if(coin[1]>1) coin[1]--;
                else coin[0]=coin[0]-2;
            }
        }
        return true;
    }
};