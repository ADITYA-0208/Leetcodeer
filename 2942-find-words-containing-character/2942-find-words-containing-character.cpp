class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int k=0;
        for(auto it: words){
            for(int i=0;i<it.size();i++){
                if(it[i]==x){
                    ans.push_back(k);
                    break;
                }
            }
            k++;
        }
        return ans;
    }
};