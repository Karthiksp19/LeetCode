class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1, sum = 0;
        int n = digits.size();
        for (int i = 0; i < n; i++){
            sum = digits[i] + carry;
            carry = sum / 10;
            sum = sum % 10;
            digits[i] = sum;
        }
        if(carry != 0) digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};