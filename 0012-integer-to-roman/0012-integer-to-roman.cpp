class Solution {
public:
    string intToRoman(int no) {
        string nums[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int numsi[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        string ans = "";
        for (int i = 0; i < 13; i++){
            int num = numsi[i];
            while(no >= num){
                ans.append(nums[i]);
                no = no - num;
            }
        }        

        return ans;
    }
};

// string ans = "";
//         int div = 1000;
//         while (no > div || div > 0){
//             int digit = no - 1000;
//             ans.append(num[digit]);
//             no = no - 1000;
//             if (no < div) {
//                 div = div / 10;
//             }
//         }
