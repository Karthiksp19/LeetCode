class Solution {
public:
    void helper(int idx, vector<int> &curr, vector<vector<int>> &ans, vector<int>& nums){
        cout << idx << endl;
        int n = nums.size();
        ans.push_back(curr);
        if (idx == n){
            return;
        }

        for (int i = idx; i < n; i++){
            if(i > idx && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            helper(i + 1, curr, ans, nums);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> curr;
        helper(0, curr, ans, nums);
        return ans;
    }
};