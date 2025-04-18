class Solution {
public:
    string countAndSay(int n) {
        if (n==1) return "1";
        auto fc=fucc(n);
        return stringcon(fc);
    }
    string stringcon(vector<pair<int,char>> recc){
        string s="";
        for(auto & [count,it] : recc){
            s+=to_string(count);
            s+=it;
        }
        return s;
    }
    vector<pair<int,char>> fucc(int n){
        if(n==2) return {{1,'1'}};
        vector<pair<int,char>> recc=fucc(n-1);
        string s=stringcon(recc);
        char c=s[0];
        vector<pair<int,char>>vec;
        vec.push_back({1,s[0]});
        for(int i=1;i<s.size();i++){
            if(s[i]==c)vec.back().first++;
            else  {   vec.push_back({1,s[i]});c=s[i];}
        }
        return vec;
    }
};