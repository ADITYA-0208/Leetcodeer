class Solution {
public:
    int setbits(int n) {
        return __builtin_popcount(n); 
    }
    int minimizeXor(int num1, int num2) {
        int set1=setbits(num1);
        int set2=setbits(num2);
        if(set1==set2)  return num1;
        if(set1<set2) {
            for(int i=num1;i<1000;i++){
                if(setbits(i)==set2){
                    return i;
                }
            }
        }
        if(set1>set2) {
            for(int i=num1;i>=0;i--){
                if(setbits(i)==set2){
                    return i;
                }
            }
        }
        return -1;
    }
};