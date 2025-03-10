class Solution {
public:
    bool isval(char b){
        if(b=='a' || b=='e' || b=='i' || b=='o' || b=='u')  return true;
        return false;
    }
    long long countOfSubstrings(string word, int k) {
        return countOf(word,k)-countOf(word,k+1);
    }
    long long countOf(string word, int k) {
        int n=word.size();
        long long ans=0;
        int p=0;
        int l=0,r=0;
        unordered_map<char,int>map1;
        while(r<n){
            if(isval(word[r])){
                map1[word[r]]++;
            }
            else{
                p++;
            }
            while((map1.size()==5) && (p>=k)){
                ans+=n-r;
                if(isval(word[l])){
                    map1[word[l]]--;
                    if(map1[word[l]]==0){
                        map1.erase(word[l]);
                    }
                }
                else{
                    p--;
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};