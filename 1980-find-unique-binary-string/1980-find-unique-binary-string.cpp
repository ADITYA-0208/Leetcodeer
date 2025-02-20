class Solution {
public:
    string intToBinary(int num, int n) {
        string binary = bitset<32>(num).to_string();  
        return binary.substr(32 - n);  
    }
    int binaryToInt(const string& binary) {
        return stoi(binary, nullptr, 2); 
    }

    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin(),nums.end());
        string ans="";
        unordered_set<string>set1(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)    ans+='0';
        while(1){
            if(set1.find(ans)==set1.end()){
                return ans;
            }
            int x=binaryToInt(ans);
            x++;
            ans=intToBinary(x,nums.size());
        }
        return "";
    }
};
