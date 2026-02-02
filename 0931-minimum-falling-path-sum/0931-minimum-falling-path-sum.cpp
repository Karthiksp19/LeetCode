class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp = matrix;

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int up = dp[i - 1][j];
                int upl = (j > 0) ? dp[i - 1][j - 1] : 1e9;
                int upr = (j < n - 1) ? dp[i - 1][j + 1] : 1e9;

                dp[i][j] += min({up, upl, upr});
            }
        }

        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};