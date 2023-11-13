# ------------------------------------------------------------------------------
# See cc version for notes
# ------------------------------------------------------------------------------
from typing import List

def maxProfit(prices: List[int]) -> int:
    if len(prices) <= 1:
        return 0
    buy_price = prices[0]
    max_profit = 0
    for i in range(1, len(prices)):
        buy_price = min(buy_price, prices[i])
        max_profit = max(max_profit, prices[i] - buy_price)
    return max_profit
