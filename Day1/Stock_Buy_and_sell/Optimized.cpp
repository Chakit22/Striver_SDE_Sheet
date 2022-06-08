//Based on the concept of hills and valleys
//if the current value is less than minprice then keep on updating that value as on the right if some greater value exists
//then it will have a higher profit with this value because profit exists only when a vlue on the right side is
//greater than this minvalue.
int maxProfit(vector<int>& prices)
{
    int minprice = INT_MAX;
    int maxprofit = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < minprice)
            minprice = prices[i];  //keep on updating the minimum
        else if (prices[i] - minprice > maxprofit)  //if found a value greater than this value then keep on updating
            //the maxprofit.
            maxprofit = prices[i] - minprice;
    }
    return maxprofit;
}
