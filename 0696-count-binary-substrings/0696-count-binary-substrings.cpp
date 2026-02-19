class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> groups;
        int count = 1;
        int n = s.size();
        char prev = s[0];
        int ans = 0;
        for (int i = 1; i < n; i++){
            char ch = s[i];
            if(ch == prev){
                count++;
            }
            else{
                prev = ch;
                groups.push_back(count);
                count = 1;
            }
        }
        groups.push_back(count);

        int m = groups.size();
        for (int i = 1; i < m; i++){
            ans += min(groups[i - 1], groups[i]);
        }

        return ans;
    }
};