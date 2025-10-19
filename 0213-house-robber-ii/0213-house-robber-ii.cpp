class Solution {
public:
    int helper(vector<int> &nums){
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        
        vector<int> ans(n, 0);
        ans[0] = nums[0];
        ans[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++){
            int skip = ans[i - 1];
            int take = nums[i] + ans[i - 2];
            ans[i] = max(skip, take);
        }

        return ans[n - 1];
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        vector<int> num1(nums.begin() + 1, nums.end());
        vector<int> num2(nums.begin(), nums.end() - 1);

        int ans1 = helper(num1);
        int ans2 = helper(num2);

        return max(ans1, ans2);
    }
};