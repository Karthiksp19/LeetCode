class Solution {
public:
    bool isPowerOfTwo(int n) {
        // return !(n & 1) || n == 1; error
        int sum = 0;
        while (n > 0){
            // sum += n & 1 error
            sum += 1;
            n = n & n - 1;
            cout << n << endl;
        }

        return (sum == 1) ? true : false;
    }
};