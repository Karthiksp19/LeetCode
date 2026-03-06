class Solution {
public:
    bool checkOnesSegment(string s) {
        int count = 0;
        int tc = 0;
        int n = s.size();
        for (int i = 0; i < n; i++){
            if(s[i] == '1'){
                if(count == 0) tc++;
                count++;
            }
            else{
                count = 0;
            }
        }

        return (tc <= 1) ? true : false;
    }
};