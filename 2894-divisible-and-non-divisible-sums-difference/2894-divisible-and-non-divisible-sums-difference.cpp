class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum=n*(n+1)/2;
        int num2=0;
        for(int i=1;i<=n;i++){
            if(i%m==0)   num2+=i;
        }
        int num1=sum-num2;
        cout<<sum;
        return num1-num2;
    }
};