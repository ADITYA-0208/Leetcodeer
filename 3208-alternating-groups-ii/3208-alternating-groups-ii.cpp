class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ind=0;
        int n=colors.size();
        for(int i=0;i<colors.size();i++){
            if(colors[i%n]==colors[(i+1)%n]){
                ind=(i+1)%n;break;
            }
        }
        int p=1,ans=0;
        for(int i=1;i<colors.size()+k-1;i++){
            int prev=(ind+i-1)%n;
            int next=(ind+i)%n;
    
            if(colors[prev]!=colors[next])  p++;
            else    p=1;
            if(p==k)  {ans++;p--;}
        }
        return ans;
    }
}; 