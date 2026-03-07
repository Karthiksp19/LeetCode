class Solution {
public:
    void helper(int idx, int k, int n, vector<int> &nums, vector<int> &res, vector<vector<int>> &ans){
        if(n == 0 && k == 0){
            ans.push_back(res);
            return;
        }
        if(k == 0){
            return;
        }

        for (int i = idx; i < nums.size(); i++){
            res.push_back(nums[i]);
            helper(i + 1, k - 1, n - nums[i], nums, res, ans);
            res.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> res;
        vector<vector<int>> ans;
        helper(0, k, n, nums, res, ans);
        return ans;
    }
};