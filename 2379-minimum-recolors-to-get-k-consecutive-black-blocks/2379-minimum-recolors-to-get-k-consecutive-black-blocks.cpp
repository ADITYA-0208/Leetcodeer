class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int w = 0;
        for (int i = 0; i < k; i++) {
            if(blocks[i]=='W')  
                w++;
        }
        int mini = w;
        int l = 0, h = k;
        while(h<blocks.size()){
            if(blocks[l]=='W')    w--;
            if(blocks[h]=='W')  w++; 
            mini=min(mini, w); 
            l++; h++;  
        }

        return mini;
    }
};
