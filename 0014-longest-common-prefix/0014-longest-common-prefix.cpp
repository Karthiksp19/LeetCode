class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int k = 0;
        for (int i = 0; i < strs[0].size(); i++) {
            bool is = true;
            for (int j = 0; j < strs.size(); j++) {
                if (strs[0][i] != strs[j][i]) {
                    is = false;
                    break;
                }
            }
            if(is) k++;
            else break;
        }
        cout << k;
        return strs[0].substr(0,k);
    }
};