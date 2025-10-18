class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIdx = nums[0];
        for (int i = 1; i < n; i++){
            if(i > maxIdx) return false;


            maxIdx = max(maxIdx, i + nums[i]);
        }

        return true;
    }
};