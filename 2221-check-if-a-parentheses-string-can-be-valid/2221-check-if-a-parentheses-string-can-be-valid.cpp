class Solution {
public:
    bool canBeValid(string s, string locked) {
        int close =0,open=0,wildc=0;
        if(s.size()%2!=0)   return false;
        for(int i=0;i<s.size();i++){
            if(s[i]==')' && locked[i]==1){
                if(wildc+open<=close)   return false;
                close++;    
            }
            if(s[i]=='(' && locked[i]==1){
                open++;    
            }
            if(locked[i]==0)    wildc++;
        }
        close =0,open=0,wildc=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')' && locked[i]==1){
                close++;    
            }
            if(s[i]=='(' && locked[i]==1){
                if(wildc+close<=open)   return false;
                open++;    
            }
            if(locked[i]==0)    wildc++;
        }
        return true;
    }
};














// class Solution {
// public:
//     bool canBeValid(string s, string locked) {
//         stack<pair<char, int>> stack;
//         if (s.size() % 2 != 0) return false; // Length must be even
        
//         for (int i = 0; i < s.size(); i++) {
//             if ((s[i] == ')') && stack.empty() && locked[i] == '0') {
//                 stack.push({'(', locked[i]});
//             } 
//             else if ((s[i] == ')') && stack.empty() && locked[i] == '1') {
//                 return false;
//             } 
//             else if (s[i] == ')' && !stack.empty()) {
//                 if (stack.top().first == '(' && s[i] == ')') {
//                     stack.pop();
//                 } 
//                 else if (stack.top().first == ')' && s[i] == ')' && stack.top().second == '0') {
//                     stack.pop();
//                 } 
//                 else {
//                     return false;
//                 }
//             }
//             else if (s[i] == '(' && locked[i] == '1') {
//                 stack.push({s[i], locked[i]});
//             }
//             else if (s[i] == '(' && locked[i] == '0') {
//                 if (!stack.empty() && stack.top().first == '(') {
//                     stack.pop();
//                 } 
//                 else {
//                     stack.push({s[i], locked[i]});
//                 }
//             }
//         }

//         if (!stack.empty()) return false;
//         return true;
//     }
// };
