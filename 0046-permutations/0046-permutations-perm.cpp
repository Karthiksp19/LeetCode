class Solution {
public:
    void helper(int idx, vector<vector<int>> &ans, vector<int> &nums){
        int n = nums.size();

        if(idx == n){
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < n; i++){
            swap(nums[idx], nums[i]);
            helper(idx + 1, ans, nums);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0, ans, nums);
        return ans;
    }
};