class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        for(auto ch :s){    
            map[ch]++;
        }
        priority_queue<pair<int,char> > g;
        for(auto it :map){
            g.push({it.second, it.first});
        }
        string result = "";
        while (!g.empty()) {
            auto top = g.top();
            g.pop();
            result += string(top.first, top.second);
        }
        return result;
    }
};