class MapSum:

    def __init__(self):
        self.map = {}
        self.score = collections.Counter()

    def insert(self, key: str, val: int) -> None:
        delta = val - self.map.get(key, 0)
        self.map[key] = val
        for i in range(len(key) + 1):
            prefix = key[:i]
            self.score[prefix] += delta

    def sum(self, prefix: str) -> int:
        return self.score[prefix]


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)