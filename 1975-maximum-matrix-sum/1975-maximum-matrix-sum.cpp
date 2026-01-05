class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        int count = 0;
        long long mini = LLONG_MAX;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                sum += abs((long long)matrix[i][j]);
                if (matrix[i][j] < 0) count++;
                mini = min(mini, abs((long long)matrix[i][j]));
            }
        }
        return (count % 2) ? sum - 2 * mini : sum;
    }
};
