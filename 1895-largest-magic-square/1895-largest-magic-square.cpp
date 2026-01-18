class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> row(m, vector<int>(n + 1, 0));
        vector<vector<int>> col(m + 1, vector<int>(n, 0));
        vector<vector<int>> diag(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> anti(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
                diag[i + 1][j + 1] = diag[i][j] + grid[i][j];
                anti[i + 1][j] = anti[i][j + 1] + grid[i][j];
            }
        }

        int maxK = min(m, n);

        for (int k = maxK; k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    int target = row[i][j + k] - row[i][j];
                    bool ok = true;

                    for (int r = 0; r < k && ok; r++) {
                        if (row[i + r][j + k] - row[i + r][j] != target)
                            ok = false;
                    }

                    for (int c = 0; c < k && ok; c++) {
                        if (col[i + k][j + c] - col[i][j + c] != target)
                            ok = false;
                    }

                    int d1 = diag[i + k][j + k] - diag[i][j];
                    int d2 = anti[i + k][j] - anti[i][j + k];

                    if (d1 != target || d2 != target)
                        ok = false;

                    if (ok)
                        return k;
                }
            }
        }
        return 1;
    }
};
