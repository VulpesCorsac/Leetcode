class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        low = float('inf')
        profit = 0
        for price in prices:
            profit = max(profit, price - low)
            low = min(low, price)
        return profit