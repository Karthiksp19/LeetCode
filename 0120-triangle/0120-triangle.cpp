class Solution {
public:
    int helper(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return triangle[i][j];

        if(j < 0 || j > i) return INT_MAX;

        if(dp[i][j] != -1) return dp[i][j];

        int up = helper(i - 1, j, triangle, dp);
        int upl = helper(i - 1, j - 1, triangle, dp);

        return dp[i][j] = triangle[i][j] + min(up, upl);
    }


    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        int mini = INT_MAX;
        for (int i = 0; i < m; i++){
            mini = min(mini, helper(m - 1, i, triangle, dp));
        }
        return mini;
    }
};