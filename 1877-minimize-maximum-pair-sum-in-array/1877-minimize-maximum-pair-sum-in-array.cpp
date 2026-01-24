class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxi = INT_MIN;
        int i = 0;
        while (i < n / 2){
            maxi = max(nums[i] + nums[n - i - 1], maxi);
            i++;
        }
        return maxi;
    }
};