class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        a, b = heapq.nlargest(2, nums)
        return max(enumerate(nums), key=lambda x: x[1])[0] if a >= b * 2 else -1