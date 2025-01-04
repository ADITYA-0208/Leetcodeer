//learned form chatgpt 
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>first(26,-1),last(26,-1);
        unordered_set<string> un;
        for(int i=0;i<s.size();i++){
            if(first[s[i]-'a']==-1){
                first[s[i]-'a']=i;
            }
            last[s[i]-'a']=i;
        }
        for(int i=0;i<26;i++){
            if(first[i]!=-1 || last[i]>first[i]){
                unordered_set<char> middle;
                for(int j=first[i]+1;j<last[i];j++){
                    middle.insert(s[j]);
                }
                for(auto it :middle){
                    un.insert(string(1, 'a' + i) + it + string(1, 'a' + i));
                }
            }
        }
        return un.size();
    }
};