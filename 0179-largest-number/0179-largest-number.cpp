bool compare(string a, string b) {
    return a + b > b + a; 
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for (int num : nums) {
            ans.push_back(to_string(num));
        }
        sort(ans.begin(),ans.end(), compare);
        if (ans[0] == "0") return "0";
        string result = "";
        for (string s : ans) {
            result+=s;
        }    
        return result;
    }
};