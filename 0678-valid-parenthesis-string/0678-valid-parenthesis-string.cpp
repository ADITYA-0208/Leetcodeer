class Solution {
public:
    bool checkValidString(string s) {
        stack<int>left;
        stack<int>star;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(')    left.push(i);
            else if(s[i]=='*')    star.push(i);
            else{
                if(!left.empty())   left.pop();
                else if(!star.empty())  star.pop();
                else    return false;
            }}
            while(!left.empty() && !star.empty()){
                if(left.top()< star.top()){
                    left.pop();
                    star.pop();
                }
            }
        return left.empty();
    }
};






// class Solution {
// public:
//     bool checkValidString(string s) {
//         return generateAndCheck(s, 0);
//     }
//     bool generateAndCheck(string& s, int index) {
//         if (index == s.length()) {
//             return isValid(s);
//         }

//         if (s[index] != '*') {
//             return generateAndCheck(s, index + 1);
//         }

//         s[index] = '(';
//         if (generateAndCheck(s, index + 1)) {
//             return true;
//         }

//         s[index] = ')';
//         if (generateAndCheck(s, index + 1)) {
//             return true;
//         }

//         s[index] = ' ';
//         if (generateAndCheck(s, index + 1)) {
//             return true;
//         }
//         s[index] = '*';
//         return false;
//     }
//     bool isValid(string s) {
//         stack<char>stack;
        
//         for(int i=0;i<s.size();i++){
//             if((s[i]==')') && stack.empty())  { return false;}
//             else if(s[i]==')'&& !stack.empty()){
//                if(stack.top()=='(' && s[i]==')') {stack.pop();}
//                 else   {return false;}
//             }
//             if(s[i]=='('){
//                 stack.push(s[i]);
//             }
//         }
//         if(!stack.empty())   return false;
//         return true;
//     }
// };