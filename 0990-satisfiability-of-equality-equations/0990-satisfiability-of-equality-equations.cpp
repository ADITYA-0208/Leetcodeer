class Solution {
public:
    char find1(char i, unordered_map<char, char>& parent) {
        if (parent.find(i) == parent.end()) {
            parent[i] = i;
            return i;
        }   
        if (parent[i] != i) {
            parent[i] = find1(parent[i], parent); 
        }
        return parent[i];
    }
    bool equationsPossible(vector<string>& equations) {
        unordered_map<char,char>parent1;
        unordered_map<char,char>parent2;
        for(int i=0;i<equations.size();i++){
            if(equations[i][0]==equations[i][3])    continue;
            if(equations[i][1]=='='){
                char p1=find1(equations[i][0],parent2);
                char p2=find1(equations[i][3],parent2);
                if(p1==p2)  return false;
                p1=find1(equations[i][0],parent1);
                p2=find1(equations[i][3],parent1);
                if(p1==p2)  continue;
                else parent1[p1]=p2;
            }
        }
        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='!'){
                char p1=find1(equations[i][0],parent1);
                char p2=find1(equations[i][3],parent1);
                if(p1==p2)  return false;
                p1=find1(equations[i][0],parent2);
                p2=find1(equations[i][3],parent2);
                if(p1==p2) continue;
                else    parent2[p1]=p2;
            }
        }
        return true;
    }
};