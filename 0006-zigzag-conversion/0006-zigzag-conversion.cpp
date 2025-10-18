class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.size()) return s;

        int n = s.size();
        vector<string> rows(numRows, "");
        int rown = 0;   
        bool goingDown = true;

        for (char ch : s){
            rows[rown] += ch;
            if (rown == 0)
                goingDown = true;
            else if (rown == numRows - 1)
                goingDown = false;

            rown += (goingDown ? 1 : -1);
        }

        string ans;
        for (string str : rows){
            ans += str;
        }

        return ans;
    }
};