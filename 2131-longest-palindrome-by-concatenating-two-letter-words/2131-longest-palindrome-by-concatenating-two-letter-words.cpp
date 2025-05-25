class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>map1;
        unordered_map<string,int>map2;
        int count=0;
        bool flag=false;
        for(auto it : words){
            string s2 = it;
            reverse(s2.begin(),s2.end()); 
            if(it[0]==it[1]){ 
                map2[s2]++;
            }
            //else{
            if(map1.find(s2)!=map1.end()){
                count+=4;
                map1[s2]--;
                if(map1[s2]==0) map1.erase(s2);
            }
            else    map1[it]++;//}
        }
        cout<<count;
        int maxi=0;
        for(auto it:map2){
            if(it.second%2 !=0) maxi=1;
        }
        if(maxi>0)  count+=2;
        return count;
    }
};