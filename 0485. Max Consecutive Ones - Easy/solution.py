class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        a = (''.join(map(str, nums))).split('0')
        return max(map(len, a))