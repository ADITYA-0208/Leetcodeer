class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>rightmax(n,0);
        rightmax[n-1]=height[n-1];
        for(int i=height.size()-2;i>=0;i--){
            rightmax[i]=max(rightmax[i+1],height[i]);
            //cout<<rightmax[i]<<"  "<<i<<"  ";
        } 
        int leftmax=height[0];
        int res=0;
        for(int i=0;i<height.size();i++){
            if(height[i]<leftmax && height[i]<rightmax[i])res+=min(leftmax,rightmax[i])-height[i];
            leftmax=max(leftmax,height[i]);
            cout<<leftmax<<"  "<<i<<"  ";
        }
        return res;
    }
};