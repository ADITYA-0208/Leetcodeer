class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map1;
        stack<int>st;
        int maxi=-1;
        int n=nums2.size();
        for(int i=n-1;i>=0;i--){
            maxi=-1;
            while(!st.empty()){
                if(st.top()<nums2[i]){
                    st.pop();
                }
                else{
                    maxi=st.top();
                    break;
                }
            }
            st.push(nums2[i]);
            map1[nums2[i]]=maxi;
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(map1[nums1[i]]);
        }
        return ans;
    }
};