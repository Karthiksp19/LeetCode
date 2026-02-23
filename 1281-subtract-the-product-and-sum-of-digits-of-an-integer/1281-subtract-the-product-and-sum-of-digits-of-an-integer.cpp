class Solution {
public:
    int subtractProductAndSum(int n) {
        long long sum = 0;
        long long prod = 1;

        int dig = 0;
        while(n > 0){
            dig = n % 10;
            sum += dig;
            prod *= dig;
            n = n / 10;
        }

        return prod - sum;
    }
};