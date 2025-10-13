class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0 ; i < tokens.size(); i++){
            string s = tokens[i];
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int n2 = st.top(); st.pop();
                int n1 = st.top(); st.pop();
                if(s == "+") st.push(n1 + n2);
                else if(s == "-") st.push(n1 - n2);
                else if(s == "*") st.push(n1 * n2);
                else st.push(n1 / n2);
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};