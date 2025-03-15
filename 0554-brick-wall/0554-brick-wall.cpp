class Solution {
public:
    vector<vector<long long>> convertLists(vector<vector<int>>& wall) {
        vector<vector<long long>>result(wall.size());
        for(int i=0;i<wall.size();i++){
            for(int j=0;j<wall[i].size();j++){
                if(j==0)    result[i].push_back(wall[i][j]);
                else result[i].push_back(wall[i][j]+result[i][j-1]);
            }
        }
        return result;
    }
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long ,int> map1;
        int maxi=0;
        int n=wall.size();
        vector<vector<long long>>wall1;
        wall1=convertLists(wall);
        for(int i=0;i<wall.size();i++){
            for(int j=0;j<wall[i].size()-1;j++){
                map1[wall1[i][j]]++;
                maxi=max(maxi,map1[wall1[i][j]]);
            }
        }
        return n-maxi;
    }
};