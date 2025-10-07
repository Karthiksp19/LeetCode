class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;

        while (numBottles >= numExchange){
            int newB = numBottles / numExchange;
            ans += newB;
            numBottles = newB + numBottles % numExchange;
        }

        return ans;
    }
};