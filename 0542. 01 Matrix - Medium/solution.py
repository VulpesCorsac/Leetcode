class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:

        m, n = len(matrix), len(matrix and matrix[0])
        for i in range(m):
            for j in range(n):
                if matrix[i][j] != 0:
                    matrix[i][j] = float("inf")
                    if i > 0:
                        matrix[i][j] = min(matrix[i][j], matrix[i-1][j] + 1)
                    if j > 0:
                        matrix[i][j] = min(matrix[i][j], matrix[i][j-1] + 1)

        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                if matrix[i][j] != 0:
                    if i + 1 < m:
                        matrix[i][j] = min(matrix[i][j], matrix[i+1][j] + 1)
                    if j + 1 < n:
                        matrix[i][j] = min(matrix[i][j], matrix[i][j+1] + 1)

        return matrix