class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int n = nums.size();
        int maxlen = 0, zeros = 0;
        while (right < n){
            if(nums[right] == 0) zeros++;

            while(zeros > k){
                if(nums[left] == 0) zeros--;
                left++;
            }

            int len = right - left + 1;
            maxlen  = max (len, maxlen);

            right++;
        }

        return maxlen;
    }
};