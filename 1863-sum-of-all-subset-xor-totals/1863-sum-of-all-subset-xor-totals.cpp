class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int orSum = 0;
        for (int num : nums){
            orSum |= num;
        }
        return orSum * (1 << (nums.size() - 1));
    }
};