class Solution {
public:
    bool isPalindrome(int x) {
        // int original_x = x;
        if (x < 0) 
            return false;
        int rev = 0;
        while(x > 0){
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;    
    }
};