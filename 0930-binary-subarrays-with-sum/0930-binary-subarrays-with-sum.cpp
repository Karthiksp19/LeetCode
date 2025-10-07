class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal - 1);
    }

    int helper(vector<int> &nums, int goal){
        
        if(goal < 0) return 0;

        int left = 0, right = 0;
        int n = nums.size();
        int count = 0, c = 0;
        while (right < n){
            if(nums[right] == 1) count++;
            
            while(count > goal){
                if(nums[left] == 1) count--;
                left++;
            }

            c += right - left + 1;

            right++;
        }
        cout << c;
        return c;
    }
};