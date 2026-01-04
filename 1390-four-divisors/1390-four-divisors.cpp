class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;
        
        for (int num : nums) {
            int divisorSum = 0;
            int divisorCount = 0;
            
            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    divisorCount++;
                    divisorSum += i;
                    
                    if (i != num / i) {
                        divisorCount++;
                        divisorSum += num / i;
                    }
                    
                    if (divisorCount > 4) break;
                }
            }
            
            if (divisorCount == 4) {
                totalSum += divisorSum;
            }
        }
        
        return totalSum;
    }
};










// class Solution {
// public:
//     pair<int, int> divisor(int n){
//         int c = 0;
//         int sum = 0;
//         for (int i = 1; i <= n; i++){
//             if(n % i == 0) {
//                 c++;
//                 sum += i;
//             }
//         }
//         return {c, sum};
//     }

//     int sumFourDivisors(vector<int>& nums) {
//         int n = nums.size();
//         int sum = 0;
//         for(int i = 0; i < n; i++){
//             if(divisor(nums[i]).first == 4){
//                 sum += divisor(nums[i]).second;
//             }
//         }
//         return sum;
//     }
// };