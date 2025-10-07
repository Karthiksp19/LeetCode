class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++){
            if(ans.empty() || nums[i] != ans.back()){
                ans.push_back(nums[i]);
            }
        }

        nums = ans;
        return ans.size();
    }
};