class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int count=0;
        unordered_map<int,int>map1;
        if(hand.size()<groupSize)  return false;
        sort(hand.begin(),hand.end());
        for(int i=0;i<hand.size();i++){
            map1[hand[i]]++;
        }
        for(int i=0;i<hand.size();i++){
            int mcount=0;
            if(map1[hand[i]]>0){
            for(int j=0;j<groupSize;j++){
                if(map1[hand[i]+j]>0){
                    mcount++;
                    count++;
                    map1[hand[i]+j]--;
                }
            }
            if(mcount!=groupSize)    return false;
            
        }}
        if(count==hand.size())  return true;
        return false;
    }
};