class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first < b.first;
        });

        int low = 0, high = n - 1;
        while (low < high) {
            if ((arr[low].first + arr[high].first) == target) {
                return {arr[low].second, arr[high].second};
            } else {
                if ((arr[low].first + arr[high].first) < target)
                    low++;
                else
                    high--;
            }
        }
        return {-1, -1};
    }
};