class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());

        int sum = 0;
        int carry = 1;

        for (int i = 0; i < digits.size(); i++){
            sum = digits[i] + carry;
            carry = sum / 10;
            sum = sum % 10;
            digits[i] = sum;
        }
        if (carry == 1) digits.push_back(1);

        reverse(digits.begin(), digits.end());
        return digits;
    }
};