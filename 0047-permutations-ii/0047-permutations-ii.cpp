class Solution {
public:
    void helper(int idx, vector<vector<int>> &ans, vector<int> &nums){
        int n = nums.size();
        if (idx == n){
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;
        for (int i = idx; i < n; i++){
            if(used.count(nums[i])) continue;
            used.insert(nums[i]);
            swap(nums[i], nums[idx]);
            helper(idx + 1, ans, nums);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0, ans, nums);
        return ans;
    }
};