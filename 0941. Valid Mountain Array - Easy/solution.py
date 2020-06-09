class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        if len(A) < 3 or A == sorted(set(A)) or A[::-1] == sorted(set(A)):
            return False

        l = A.index(max(A)) + 1

        return A[:l] == sorted(set(A[:l])) and A[l-1:][::-1] == sorted(set(A[l-1:]))