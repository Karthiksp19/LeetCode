class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(x == 1) return 1;
        if(n < 0){
            x = 1 / x;
            N = -N;
        }
        if(N == 0) return 1;
        if(N == 1) return x;

        double halfSqr = myPow(x, N / 2);
        if(n % 2 == 0){
            return halfSqr * halfSqr;
        }
        else{
            return halfSqr * halfSqr * x;
        }
    }
};