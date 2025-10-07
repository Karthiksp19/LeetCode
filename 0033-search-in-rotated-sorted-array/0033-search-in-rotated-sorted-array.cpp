class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n - 1;

        while (low <= high){ 
            int mid = (low + high) / 2;
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] <= nums[high]){
                if (nums[mid] < target && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
            else{
                if (nums[mid] > target && target >= nums[low]) high = mid - 1;
                else low = mid + 1;
            }
            printf("%d mid %d low %d high \n",mid, low, high);
        }

        return -1;
    }
};