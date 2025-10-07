class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num = num / 10;
        }

        while (sum > 9){
            int temp = 0;
            while (sum > 0){
                temp += sum % 10;
                sum = sum / 10;
            }
            sum = temp;
        }

        
        return sum;
    }
};