class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int max=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>max){
                max=arr[i];
            }
        }
        
        int p=0;
        int f;
        int flag=false;
        for(int i=1;i<=max;i++){
            if(k==1 && flag==true){
                
                return i;
            }
            if(i==arr[p]){
                p++;
                
            }
            else{
                k--;
                
                cout<<k<<"sdas";
                flag=true;
            }
            f=i;
        }
        
        cout<<"asdas";
        return f+k;
    }
};