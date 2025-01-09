class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs[0].size();
        int m=strs.size();
        if(m==1)    return strs[0]; 
        string prefix=strs[0].substr(0,n-1);
        for (size_t i = 1; i < strs.size(); ++i) {
            while(strs[i].find(prefix)!=0){
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) {
                    return "";
                }
            }
        }
        return prefix;
        
    }
};