class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftStack;  // Stack to store indices of '('
        stack<int> starStack;  // Stack to store indices of '*'
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                leftStack.push(i);  // Push the index of '(' onto the stack
            } else if (s[i] == '*') {
                starStack.push(i);  // Push the index of '*' onto the stack
            } else {  // s[i] == ')'
                if (!leftStack.empty()) {
                    leftStack.pop();  // Match ')' with the most recent '('
                } else if (!starStack.empty()) {
                    starStack.pop();  // Match ')' with the most recent '*'
                } else {
                    return false;  // No matching '(' or '*' found
                }
            }
        }
        
        // Now, we need to match any remaining '(' with '*' that come after them
        while (!leftStack.empty() && !starStack.empty()) {
            if (leftStack.top() < starStack.top()) {
                leftStack.pop();
                starStack.pop();
            } else {
                return false;  // No matching '*' found for the remaining '('
            }
        }
        
        // If there are no remaining '(', the string is valid
        return leftStack.empty();
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