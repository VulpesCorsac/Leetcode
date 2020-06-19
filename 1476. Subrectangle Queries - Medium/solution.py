class SubrectangleQueries:

    def __init__(self, rectangle: List[List[int]]):
        self.r = rectangle
        self.histories = []

    def updateSubrectangle(self, row1: int, col1: int, row2: int, col2: int, newValue: int) -> None:
        self.histories.append([row1, col1, row2, col2, newValue])

    def getValue(self, row: int, col: int) -> int:
        for operation in reversed(self.histories):
            if operation[0] <= row <= operation[2] and operation[1] <= col <= operation[3]:
                return operation[4]
        return self.r[row][col]



# Your SubrectangleQueries object will be instantiated and called as such:
# obj = SubrectangleQueries(rectangle)
# obj.updateSubrectangle(row1,col1,row2,col2,newValue)
# param_2 = obj.getValue(row,col)