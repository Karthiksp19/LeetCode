class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());

        int m = g.size();
        int n = s.size();
        int i = 0, j = 0 ;
        while(i < m && j < n){
            if(s[j] >= g[i]) {
                i++;
                j++;
            }
            else i++;
        }
        return j;
    }
};