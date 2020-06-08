class MyHashMap:

    def __init__(self):
        self.capacity = 8
        self.size = 0

        self.data = [(None, None)] * 8
        self.threashold = 2 / 3
        self.tomb = -1
        
    
    def hash(self, key: int) -> int:
        return key % self.capacity
    
    
    def rehash(self, h: int) -> int:
        return (5 * h + 1) % self.capacity
    

    def insertPosition(self, key: int) -> int:
        pos = self.hash(key)
        while self.data[pos] is not (None, None):
            if self.data[pos][0] == key: 
                return pos
            if self.data[pos][0] == self.tomb: 
                break
            pos = self.rehash(pos)
        return pos
        
    
    def safeAdd(self, key: int, value: int) -> None:
        pos = self.insertPosition(key)
        if pos == self.tomb: 
            return 
        self.data[pos] = (key, value)
        self.size += 1
    
    
    def safeAddList(self, data) -> None:
        for item in data: 
            if item is not (None, None): 
                self.safeAdd(item[0], item[1])

            
    def put(self, key: int, value: int) -> None:
        def addPreprocess(self) -> None:
            if self.size / self.capacity <= self.threashold: 
                return 
            
            self.capacity *= 2
            old_data = copy.deepcopy(self.data)
            self.data = [(None, None)] * self.capacity
            self.safeAddList(old_data)
        
        addPreprocess(self)
        self.safeAdd(key, value)
         
    
    def remove(self, key: int) -> None:
        pos = self.hash(key)
        while self.data[pos] is not (None, None):
            if self.data[pos][0] == key: 
                self.data[pos] = (self.tomb, None)
                self.size -= 1
                return
            pos = self.rehash(pos)
        return

    
    def get(self, key: int) -> bool:
        pos = self.hash(key)
        while self.data[pos] is not (None, None):
            if self.data[pos][0] == key: 
                return self.data[pos][1]
            pos = self.rehash(pos)
        return -1
        


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)