class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maxC = INT_MIN;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                count = 0;
            }
            else{
                count++;
                maxC = max(maxC, count);
            }
        }
        return max(maxC, count);
    }
};