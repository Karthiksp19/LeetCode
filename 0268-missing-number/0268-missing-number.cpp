class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int num = 0;

        for (int i = 0; i < n; i++){
            num = num ^ (i + 1);
            num = num ^ nums[i];
        }

        return num;
    }
};