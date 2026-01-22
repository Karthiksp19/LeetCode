class Solution {
public:
    bool increasing(vector<int> &arr){
        for (int i = 0; i < arr.size() - 1; i++){
            if(arr[i] > arr[i + 1]) return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        while(!increasing(nums)){
            int mini = INT_MAX;
            int idx = -1;
            for (int i = 1; i < nums.size(); i++){
                if(nums[i] + nums[i - 1] < mini){
                    mini = nums[i] + nums[i - 1];
                    idx = i - 1;
                }
            }

            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);
            c++;
        }
        return c;
    }
};