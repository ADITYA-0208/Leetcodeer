
//how to choose low and high (doubtful)
class Solution {
public:
    int fucc(vector<int>& weights, int days,int mid){
        int sum=0,da=1;
        for(int i=0;i<weights.size();i++){
            
            if(sum+weights[i]>mid){
                da++;
                sum=weights[i];
            }
            else{
                sum+=weights[i];
            }
        }
        return da;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(), weights.end());;
        int high=0;
        for(int i=0;i<weights.size();i++){
            high+=weights[i];
        }
        while(low<=high){
            int mid=(low+high)/2;
            if(fucc(weights,days,mid)<=days){
                high=mid-1;
            }
            else    low=mid+1;
        }
        return low;
    }
};