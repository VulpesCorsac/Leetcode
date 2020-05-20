class StockSpanner:
    
    def __init__(self):
        self.prices = []
        self.spans  = []

    def next(self, price: int) -> int:
        span = 1
        index = len(self.spans) - 1
        while index >= 0 and price >= self.prices[index]:
            span += self.spans[index]
            index -= self.spans[index]
        
        self.spans.append(span)
        self.prices.append(price)
        return span

    
# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)