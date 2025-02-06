class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        map<int,int>map1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                    map1[nums[i]*nums[j]]++;
            }
        }
        for(auto it: map1){
            int p=it.second;
            
            if(p>1){
                count+=8*(p)*(p-1)/2;
            }
        }
        return count;
    }
};