int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int profit = 0;
    //Calculate the profit for each and every pair in this array.
    //find the aximum out of those pairs
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            profit = max(profit, prices[j] - prices[i]);
        }
    }
    return profit;
}
