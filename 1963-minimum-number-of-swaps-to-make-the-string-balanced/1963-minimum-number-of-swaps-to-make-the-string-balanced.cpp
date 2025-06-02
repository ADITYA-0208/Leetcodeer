class Solution {
public:
    int minSwaps(string s) {
        int open=0,close=0,unbalance=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==']')   close++;
            if(s[i]=='[')   open++;
            if(close>open)  {unbalance++;close--;}
        }
        return (unbalance+1)/2;
    }
};