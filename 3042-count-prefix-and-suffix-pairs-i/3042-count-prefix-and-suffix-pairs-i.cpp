class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int k=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(isPrefixAndSuffix(words[i],words[j])){
                    k++;
            }
        }}
        return k;
        }
    bool isPrefixAndSuffix(string s1,string s2){
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                return false;
            }
        }
        int n=s1.size();
        int m=s2.size();
        int d=m-n;
        for(int j=n-1;j>=0;j--){
            if(s1[j]!=s2[j+d]){
                return false;
            }
        }
        return true;
    }

};