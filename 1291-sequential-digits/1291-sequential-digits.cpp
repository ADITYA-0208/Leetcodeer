class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digit="123456789";
        int length=to_string(low).size();
        vector<int>ans;
        int num=0,i=0;
        while(length <= digit.size()){
            if(i+length>digit.size()){  length++;i=0;continue;}
            num=stoi(digit.substr(i,length));
            if(num>=low && num<=high)ans.push_back(num);
            i++;
            
        }
        return ans;
    }
};