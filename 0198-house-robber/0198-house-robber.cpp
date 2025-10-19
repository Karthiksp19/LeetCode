class Solution {
public:
    int helper(int idx, vector<int> &nums, vector<int> &dp){
        int n = nums.size();
        if(idx >= n){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }
         
        int skip = helper(idx + 1, nums, dp);
        int take = nums[idx] + helper(idx + 2, nums, dp);

        return dp[idx] = max(skip, take);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return helper(0, nums, dp);
    }
};