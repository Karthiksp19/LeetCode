class Solution {
public:
    int expand(int s, int e, string& str){
        int low = s, high = e;
        int n = str.size();
        while(low >= 0 && high < n){
            if(str[low] != str[high]){
                break;
            }
            low--;
            high++;
        }

        return high - low - 1;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int maxl = 0, len = 0, start = 0;
        for (int i = 0; i < n; i++){
            int odd = expand(i, i, s);
            int even = expand(i, i + 1, s);
            len = max(odd, even);
            if(maxl < len){
                cout << "u";
                start = i - (len - 1)/ 2;
                maxl = len;
            }
        }

        return s.substr(start, maxl);
    }
};