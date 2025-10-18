class Solution {
public:
    int pascal(int n, int r){
        if (r > n - r)  r = n - r;

        long long res = 1;
        for (int i = 0; i < r; i++){
            res = res * (n - i);
            res = res / (i + 1);
        }
        return res;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++){
            vector<int> ans;
            for (int j = 0; j <= i; j++){
                ans.push_back(pascal(i, j));
            }
            res.push_back(ans);
        }
        return res;
    }
};