#include <iostream>

/* -----------------------------------------------------------------------------
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * 
 * Solution Description:
 * The main idea here is that as we iterate through the stock prices, if/when we
 * encounter a price that is lower than our current buy price, then it makes
 * more sense to buy at the lower price. In a sense then we are simply finding
 * the index of the min value and then finding the max value after that index.
 * Rather than iterating through the array twice, we simply perform the check on
 * every iteration. If we have already seen the minimum price then we will only
 * be calculating the max price, if we encounter a price that is lower than our
 * buy price then we update both buy price and profit.
 *
 * Steps:
 * 1 - Create two variables; buy_price and max_profit. Initialize max_profit to
 * zero and buy_price to the value at index 0
 * 2 - Iterate through the array indices 1 through the end, since we already
 * used the zeroth index for our initial buy_price
 * 3 - On each iteration update the buy_price using the min function
 * 4 - After updating buy_price as needed update profit using the max function
 *
 * Complexity Analysis:
 * Time: O(n) because we must always iterate through the entire input array
 * Space: O(1) becuase we only ever allocate two variables regardless of input
 * size.
 *
 * -----------------------------------------------------------------------------
 */

int maxProfit(const std::vector<int>& prices) {
	if (prices.size() <= 1) {
		return 0;
	}
	int buy_price{prices[0]};
	int max_profit{0};
	for (size_t i = 1; i < prices.size(); ++i) {
		buy_price = std::min(buy_price, prices[i]);
		max_profit = std::max(max_profit, prices[i] - buy_price);
	}
	return max_profit;
}

