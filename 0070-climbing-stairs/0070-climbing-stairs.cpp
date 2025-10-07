class Solution {
public:
    
    int climbStairs(int n) {
        int c1 = 1, c2 = 1, c3 = 1;

        for (int i = 1; i < n; i++){
            c3 = c1 + c2;
            c1 = c2;
            c2 = c3;
        }
        return c3;
    }
};