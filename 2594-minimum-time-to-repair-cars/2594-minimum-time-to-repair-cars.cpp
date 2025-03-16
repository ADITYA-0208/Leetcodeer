typedef long long ll;
class Solution {
public:
    bool fucc(vector<int>& ranks, int cars ,long long mid){
       ll p = 0;
        for(int i=0;i<ranks.size();i++) {
            p+=sqrt(mid/ranks[i]);
            if(p>=cars) return true;
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        ll r= (ll)*min_element(ranks.begin(),ranks.end())*cars*cars;
        ll l=1;
        int n=ranks.size();
        ll ans;
        //r=r*(cars-n-1)*(cars-n-1);

        while(l<=r){
            ll mid=l+(r-l)/2;
            if(fucc(ranks,cars,mid)){
                r=mid-1;
                ans=mid;
            }
            else    l=mid+1;
        }
        return ans;
    }
};