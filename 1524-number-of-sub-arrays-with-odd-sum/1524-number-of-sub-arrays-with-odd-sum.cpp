class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ocount = 0, ecount = 1;
        int sum = 0, result = 0, mod = 1e9 + 7;

        for (int num : arr) {
            sum +=num;
            if (sum % 2 == 0) {
                result=(result+ocount)%mod;
                ecount++;
            } 
            else {
                result=(result+ecount)%mod;
                ocount++;
            }
        }
        return result;
    }
};
