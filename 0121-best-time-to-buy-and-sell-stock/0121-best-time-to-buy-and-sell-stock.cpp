class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = prices[0];
        int profit = 0;
        int n = prices.size();

        for (int i = 0; i < n; i++){
             lowest = min(prices[i], lowest);
             profit = max(profit, prices[i] - lowest);
        }

        return profit;
    }
};