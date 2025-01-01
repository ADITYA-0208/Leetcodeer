class Solution {
public:
    int maxScore(string s) {
        int one=0;
        string t=s;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')   one++;
        }
        int maaxi=0;
        int zero=0,onec=one;
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='0')   zero++;
            else            onec--;

            maaxi=max(maaxi,onec+zero);
        }
        return maaxi;
    }
};