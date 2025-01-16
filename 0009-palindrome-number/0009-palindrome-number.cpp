class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
       if(x==reverse(x))    return true;
       return false;
    }
     int reverse(int x) {
        int rev = 0; 
        while (x != 0) {
            int digit = x % 10; 
            x /= 10; 
            if (rev > INT_MAX / 10) {
                return 0; // Overflow
            }
            if (rev < INT_MIN / 10 ) {
                return 0;
            }
            rev = rev * 10 + digit; 
        }
        return rev;
    }
};