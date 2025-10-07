class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int posI = 0;
        int negI = 1;

        for (int i = 0; i < n; i++){
            if (nums[i] >= 0){
                ans[posI] = nums[i];
                posI = posI + 2;
            }
            else{
                ans[negI] = nums[i];
                negI = negI + 2;
            }
        }

        return ans;
    }
};