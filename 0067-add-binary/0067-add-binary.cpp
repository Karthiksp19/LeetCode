class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        if(a.size() < b.size()){
            return addBinary(b, a);
        }

        int m = a.size();
        int n = b.size();
        int carry = 0;
        for (int i = 0; i < m; i++){
            int ai = a[m - i - 1] - '0';
            int bi = i >= n ? 0 : b[n - i - 1] -'0';
            int sum = ai + bi + carry;
            carry = sum / 2;
            ans.push_back((sum % 2) + '0');
        }
        if(carry == 1) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};