class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        trusts = [[0] * 2 for _ in range(N)]
        
        for edge in trust:
            trusts[edge[0]-1][0] += 1;
            trusts[edge[1]-1][1] += 1;
        
        for person, data in enumerate(trusts):
            if data[0] == 0 and data[1] == N-1:
                return person+1
        
        return -1