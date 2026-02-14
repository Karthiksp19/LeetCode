class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i =0 ;i < n-1 ;i = i+2){
                ans.push_back(nums[i+1]);
                ans.push_back(nums[i]);
            
        }
        return ans;
    }
};