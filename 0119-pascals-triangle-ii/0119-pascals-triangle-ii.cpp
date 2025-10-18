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
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for (int j = 0; j <= rowIndex; j++){
            ans.push_back(pascal(rowIndex, j));
        }
        return ans;
    }

};