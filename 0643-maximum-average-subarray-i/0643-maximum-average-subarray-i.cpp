class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;
        for (int i = 0; i < k; i++){
            sum += nums[i];
        }

        double avg = INT_MIN;
        for (int i = k; i < n; i++){
            cout << i << endl;
            avg = max(avg, sum / k);
            sum += nums[i];
            sum -= nums[i - k];
        }

        avg = max(avg, sum / k);
        return avg;
    }
};