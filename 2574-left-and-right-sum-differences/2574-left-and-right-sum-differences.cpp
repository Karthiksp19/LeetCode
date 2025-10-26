class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int rsum = 0, lsum = 0;
        for (int i = 0; i < n; i++){
            rsum += nums[i];
        }
        vector<int> leftsum(n, 0), rightsum(n, rsum ), ans(n, 0);

        for (int i = 0; i < nums.size(); i++){
            leftsum[i] = lsum;
            lsum += nums[i];
            rsum -= nums[i];
            rightsum[i] = rsum;
            ans[i] = abs(leftsum[i] - rightsum[i]);
        }
        return ans;
    }
};