class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int li = 0;
        for (int i = 0; i <= n; i++){
            if(s[i] == ' ' || i == n){
                reverse(s.begin() + li, s.begin() + i);
                li = i + 1 ;
            }
        }
        return s;
    }
};