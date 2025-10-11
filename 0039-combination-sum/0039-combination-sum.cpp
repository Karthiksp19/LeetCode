class Solution {
public:
    void helper(int idx, vector<int> &curr, vector<vector<int>> &ans, const vector<int>& candidates, int target){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(idx == candidates.size() || target < 0){
            return;
        }

        for (int i = idx; i < candidates.size(); i++){
            curr.push_back(candidates[i]);
            helper(i, curr, ans, candidates, target - candidates[i]);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(0, curr, ans,candidates, target);
        return ans;
    }
};