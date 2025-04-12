class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            int len = s.size();
            if (len % 2 != 0) continue;  
            int n = len / 2;
            int sum1=0,sum2=0;
            for(int j=0;j<n;j++){
                sum1+=s[j]-'0';
                sum2+=s[j+n]-'0';
            }
            if(sum1==sum2)  {count++;}
        }
        return count;
    }
};