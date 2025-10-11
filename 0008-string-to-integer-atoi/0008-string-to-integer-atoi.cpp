class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' '){
            i++;
        }

        int sign = 1;
        if(i  < n && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-') sign = -sign;
            i++;
        }

        long res = 0;
        while(i < n && isdigit(s[i])){
            int dig = s[i] - '0';
            res = res * 10 + dig;

            if(sign * res  < INT_MIN) return INT_MIN;
            if(sign * res > INT_MAX) return INT_MAX;
            i++;
        }

        return sign * res;
    }
};