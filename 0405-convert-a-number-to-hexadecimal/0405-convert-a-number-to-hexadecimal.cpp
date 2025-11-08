class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        vector<char> hex = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        string ans = "";
        unsigned int n = (unsigned int) num;
        while(n > 0){
            ans.push_back(hex[n % 16]);
            n= n / 16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};