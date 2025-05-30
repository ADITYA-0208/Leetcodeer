class Solution {
public:
    bool sumGame(string num) {
        int n=num.length()/2;
        double sum=0;
        for(int i=0;i<n;i++){
            if(num[i]=='?') sum+=4.5;
            else sum+=(num[i]-'0');
        }
        cout<<sum;
        for(int i=n;i<2*n;i++){
            if(num[i]=='?') sum-=4.5;
            else sum-=(num[i]-'0');
        }
        if(sum==0) return false;
        return true;
    }
};