class MyHashSet:

    def __init__(self):
        self.capacity = 8
        self.size = 0

        self.data = [None] * 8
        self.threashold = 2 / 3
        self.tomb = -1


    def hash(self, key: int) -> int:
        return key % self.capacity


    def rehash(self, h: int) -> int:
        return (5 * h + 1) % self.capacity


    def insertPosition(self, key: int) -> int:
        pos = self.hash(key)
        while self.data[pos] is not None:
            if self.data[pos] == key:
                return self.tomb
            if self.data[pos] == self.tomb:
                break
            pos = self.rehash(pos)
        return pos


    def safeAdd(self, key: int) -> None:
        pos = self.insertPosition(key)
        if pos == self.tomb:
            return
        self.data[pos] = key
        self.size += 1


    def safeAddList(self, data: List[int]) -> None:
        for val in data:
            if val is not None:
                self.safeAdd(val)


    def add(self, key: int) -> None:
        def addPreprocess(self) -> None:
            if self.size / self.capacity <= self.threashold:
                return

            self.capacity *= 2
            old_data = copy.deepcopy(self.data)
            self.data = [None] * self.capacity
            self.safeAddList(old_data)

        addPreprocess(self)
        self.safeAdd(key)


    def remove(self, key: int) -> None:
        pos = self.hash(key)
        while self.data[pos] is not None:
            if self.data[pos] == key:
                self.data[pos] = self.tomb
                self.size -= 1
                return
            pos = self.rehash(pos)
        return


    def contains(self, key: int) -> bool:
        pos = self.hash(key)
        while self.data[pos] is not None:
            if self.data[pos] == key:
                return True
            pos = self.rehash(pos)
        return False



# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)