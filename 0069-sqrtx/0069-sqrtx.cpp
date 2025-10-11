class Solution {
public:
    int mySqrt(int x) {
        long long low = 0, high = (long long)x + 1;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (mid * mid <= x)
                low = mid + 1;
            else
                high = mid;
        }

        return (int)(low - 1);
    }
};