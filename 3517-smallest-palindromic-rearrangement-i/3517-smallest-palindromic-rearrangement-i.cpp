class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n==1)    return s;
        string p=s.substr(0,n/2);
        char a=s[n/2];
        string result;
        if(n%2==0){
            sort(p.begin(),p.end());
            result+=p;
            reverse(p.begin(),p.end());
            result+=p;
        }  
        else{
            sort(p.begin(),p.end());
            result+=p;
            result+=a;
            reverse(p.begin(),p.end());
            result+=p;
        }
        return result;
    }
};