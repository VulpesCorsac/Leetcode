class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        ans = [1]

        for row_num in range(rowIndex+1):
            row = [None for _ in range(row_num+1)]
            row[0], row[-1] = 1, 1

            for j in range(1, len(row)-1):
                row[j] = ans[j-1] + ans[j]

            ans = row

        return ans