class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> map1;
        for(int i=0;i<s.size();i++){
            map1[s[i]]++;
        }
        int k=0;
        for(auto [cha,it] :map1){
            k += (it - 1) / 2;
        }
        
        return s.size()-k*2;
    }
};