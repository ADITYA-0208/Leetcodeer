class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int>hash;
        for(int i=0;i<n;i++){
            int x=i;sum=0;
            while(x>0){
                sum+=x%10;
                x=x/10;
            }
            hash[sum]++;
        }
         int maxSize = 0, count = 0;
        for (auto& [sum,freq]:hash) {
            if (freq > maxSize) {
                maxSize = freq;
                count = 1;
            } 
            else if (freq == maxSize) {
                count++;
            }
        }
        return count;
    }
};