class Solution {
public:
    void helper(int idx, vector<int> &curr, vector<vector<int>> &ans, vector<int> &nums){
        int n = nums.size();
        ans.push_back(curr);

        if(idx == n) return;

        for (int i = idx; i < n; i++){
            curr.push_back(nums[i]);
            helper(i + 1, curr, ans, nums);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(0, curr, ans, nums);
        return ans;
    }
};