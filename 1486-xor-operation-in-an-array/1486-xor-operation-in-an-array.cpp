class Solution {
public:
    int xorOperation(int n, int start) {
        int bitwise_xor = 0;
        for (int i = 0; i < n; i++){
            bitwise_xor ^= start + 2 * i;
        }
        return bitwise_xor;
    }
};