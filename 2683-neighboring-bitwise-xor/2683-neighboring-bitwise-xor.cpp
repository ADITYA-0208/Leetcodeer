class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        bool flag1=false,flag2=false;
        int val=1;
        int n=derived.size();
        if(n==1 && derived[0]==1)    return false;
         if(n==1 && derived[0]==0)    return true;
         if(n==2){
            for (int o0 = 0; o0 <= 1; o0++) {
            for (int o1 = 0; o1 <= 1; o1++) {
                // Generate derived array from this combination
                int d0 = o0 ^ o1; // derived[0] = original[0] ⊕ original[1]
                int d1 = o1 ^ o0; // derived[1] = original[1] ⊕ original[0]
                
                // Check if this matches the input derived array
                if (d0 == derived[0] && d1 == derived[1]) {
                    return true;
                }
            }
        }
        
        // No valid combination found
        return false;
         }
        for(int i=0;i<derived.size()-1;i++){
            cout<<val<<" "<<i<<endl;
            if(derived[i]==1)   val=1-val;
            
        }
        cout<<(val^1);
        if((val^1)==derived[n-1])  return true;
        int val2=0;
        
        for(int i=0;i<derived.size()-1;i++){
            if(derived[i]==1)   val=1-val;
            
        }
        if((val^0)==derived[n-1])  return true;
        else    flag2=false;

        //if(flag1 || flag2)  return true;
        return false;

    }
};