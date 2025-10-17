class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for (int i = 0; i < columnTitle.size(); i++){
            char ch = columnTitle[i];
            ans = ((ch - 'A') + 1) + ans * 26;
        }
        return ans;
    }
};