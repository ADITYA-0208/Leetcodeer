class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int k=0;
        for(auto it:words){
            if(isPrefixAndSuffix(pref,it)){
                k++;
            }
        }
        return k;
    }
    bool isPrefixAndSuffix(string s1,string s2){
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                return false;
            }
        }
        return true;
    }
};