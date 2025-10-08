class Solution {
public:
    string toLetterCombo(char ch){
        vector<string> digit_maps = {"","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        return digit_maps[ch - '0'];
    }

    void helper(int idx, string digits, string ans, vector<string> &answers){
        if(idx == digits.size()){
            answers.push_back(ans);
            return;
        }

        string str = toLetterCombo(digits[idx]);

        for (int i = 0; i < str.size(); i++){
            helper(idx + 1, digits, ans + str[i], answers);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> answers;
        if (digits.empty()) return answers;
        helper(0, digits,"", answers);
        return answers;
    }
};