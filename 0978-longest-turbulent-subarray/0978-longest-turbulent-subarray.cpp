class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int l=0,len=1,maxi=1;
        int n=arr.size();
        for(int i=1;i<n;i++){
            if(i%2!=0 && arr[i]<arr[i-1]){
                len=i-l+1;
                maxi=max(maxi,len);
                continue;
            }
            if(i%2==0 && arr[i]>arr[i-1]){
                len=i-l+1;
                maxi=max(maxi,len);
                continue;
            }
            else{
                l=i;
            }
        }
        l=0;
        cout<<maxi;
        for(int i=1;i<n;i++){
            if(i%2!=0 && arr[i]>arr[i-1]){
                len=i-l+1;
                maxi=max(maxi,len);
                continue;
            }
            if(i%2==0 && arr[i]<arr[i-1]){
                len=i-l+1;
                maxi=max(maxi,len);
                continue;
            }
            else{
                l=i;
            }
        }

        return maxi;
    }
};