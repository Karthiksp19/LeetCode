class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int num = x;
        int rev = 0;
        while (num > 0){
            if (rev > INT_MAX / 10) return false;
            rev = rev * 10 + num % 10;
            num = num / 10;
        }

        return rev == x ;
    }
};