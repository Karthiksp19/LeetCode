class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++){
            int low = i + 1, high = n - 1;
            while(low < high){
                int currSum = nums[i] + nums[low] + nums[high];
                if(abs(target - currSum) < abs(target - closestSum)){
                    closestSum = currSum;
                }

                if(currSum < target){
                    low++;
                }
                else if(currSum > target){
                    high--;
                }
                else{
                    return currSum;
                }
            }
        }

        return closestSum;        
    }
};