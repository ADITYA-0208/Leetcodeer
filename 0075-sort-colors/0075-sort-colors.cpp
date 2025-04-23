class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int arr[3]={0};
        int it;
        int k0=0,k1=0,k2=0;
        for(auto it :nums){
            arr[it]++;
            
        }
        for(int i=0;i<arr[0];i++){       
            nums[i]=0;
        }
        for(int i=arr[0];i<arr[0]+arr[1];i++){       
            nums[i]=1;
        }
        for(int i=arr[0]+arr[1];i<arr[0]+arr[1]+arr[2];i++){       
            nums[i]=2;
        }
    }
};