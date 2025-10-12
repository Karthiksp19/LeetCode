class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;

        bool is_neg = (dividend < 0) ^ (divisor < 0);

        long long dvd = abs((long long)dividend);
        long long div = abs((long long)divisor);
        int quo = 0;

        while (dvd >= div){
            long long temp = div;
            int val = 1;
            while (dvd > (temp << 2)){
                temp = temp << 2;
                val = val << 2;
            }
            dvd -= temp;
            quo += val;
        }

        return is_neg ? -quo : quo;
    }
};