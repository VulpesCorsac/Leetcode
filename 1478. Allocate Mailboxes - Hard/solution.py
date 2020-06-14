class Solution:
    def minDistance(self, houses: List[int], k: int) -> int:
        houses.sort()
        n = len(houses)
        
        @functools.lru_cache(None)
        def getCost(start, end):
            median = houses[(start + end) // 2]
            if (start + end) % 2 == 0:
                median = (houses[(start + end) // 2] + houses[(end + start + 1) // 2]) // 2
            return sum(abs(median - houses[j]) for j in range(start, end+1))
        
        @functools.lru_cache(None)
        def dfs(pos, k):
            if pos + k >= n:
                return 0
            if k == 0:
                return math.inf
            return min(getCost(pos, i) + dfs(i+1, k-1) for i in range(pos, n))
        
        return dfs(0, k)