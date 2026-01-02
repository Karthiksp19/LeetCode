class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mide = -1;
        int n = nums.size();
        while (low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) {
                mide = mid;
                break;
            }
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }

        if(mide == -1) return {-1, -1};

        int lowr = mide, highr = mide;
        while(lowr >= 0 && nums[lowr] == target){
            lowr--;
        }

        while(highr < n && nums[highr] == target){
            highr++;
        }

        return {lowr + 1, highr - 1};
    }
};