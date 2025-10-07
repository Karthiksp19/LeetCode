class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;
        int n = s.size();
        for (int i = 0; i < n; i++){
            char ch = s[i];
            if (ch == '[' || ch == '(' || ch == '{'){
                sk.push(ch);
            }
            else{
                if (sk.empty()) return false;

                if (sk.top() == '(' && ch == ')') sk.pop();
                else if (sk.top() == '[' && ch == ']') sk.pop();
                else if (sk.top() == '{' && ch == '}') sk.pop();
                else return false;
            }
        }

        if (!sk.empty()) return false;

        return true;
    }
};