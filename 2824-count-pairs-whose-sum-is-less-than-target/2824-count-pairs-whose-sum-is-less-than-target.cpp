class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int pairs = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low < high){
            if(nums[low] + nums[high] < target){
                pairs += high - low;
                low++;
            }
            else{
                high--;
            }
        }

        return pairs;
    }
};