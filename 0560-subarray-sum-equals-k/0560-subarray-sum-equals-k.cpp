class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int n = nums.size();
        int count = 0;
        int prefixSum = 0;
        for (int i = 0; i < n; i++){
            prefixSum += nums[i];
            int Sum = prefixSum - k;
            count += mp[Sum];
            mp[prefixSum] += 1;
        }

        return count;
    }
};