class Solution {
public:
    void left1(int i,int j,string & s){
        for(int k=i;k<=j;k++){
            s[k]='L';
        }
    }
    void right1(int i,int j,string & s){
        for(int k=i;k<=j;k++){
            s[k]='R';
        }
    }
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        int lastl=-1,lastr=-1;
        string s=dominoes;
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                if(lastr==-1)   left1(0,i,s);
                if(lastl<lastr){
                    int l = lastr, r = i;
                    while (l < r) {
                        s[l++] = 'R';
                        s[r--] = 'L';
                    }
                    lastr=-1;
                }
                
                lastl=i;
            }
            if(s[i]=='R'){
                if(lastr!=-1 && (lastl==-1 ||lastl < lastr)){
                    right1(lastr, i - 1, s);
                }
                lastr=i;
            }
            
        }
        if (lastr != -1) {
            right1(lastr, n - 1, s);
            }
        dominoes=s;
        return dominoes;
    }
};