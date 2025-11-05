class Solution {
public:
    string addStrings(string num1, string num2) {
        string n1 = num1;
        reverse(n1.begin(), n1.end());
        string n2 = num2;
        reverse(n2.begin(), n2.end());

        if(n1.length() < n2.length()){
            return addStrings(num2, num1);
        }
        int carry = 0;
        string ans = "";
        for (int i = 0; i < n1.size(); i++){
            int num1 = n1[i] - '0';
            int num2 = (i < n2.size()) ? n2[i] - '0' : 0;
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans.push_back(sum + '0');
        }

        while(carry != 0){
            ans.push_back(carry + '0');
            carry = carry / 10;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};