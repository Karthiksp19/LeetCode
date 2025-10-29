class Solution {
public:
    int fib(int n) {
        int s1 = 0, s2 = 1, s3 = 0;
        if(n < 2) return n;
        for (int i = 0; i <= n - 2; i++){
            s3 = s1 + s2;
            s1 = s2;
            s2 = s3;
        }
        return s3;
    }
};