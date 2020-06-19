class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        graph = collections.defaultdict(list)
        q = collections.deque()
        min_price = float('inf')

        for u, v, w in flights:
            graph[u].append((w, v))

        q.append((src, 0, 0))
        while q:
            city, stops, price = q.popleft()
            if city == dst:
                min_price = min(min_price, price)
                continue

            if stops <= K and price <= min_price:
                for price_to_neighbour, neighbour in graph[city]:
                    q.append((neighbour, stops+1, price+price_to_neighbour))

        return min_price if min_price!=float('inf') else -1