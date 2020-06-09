class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        n = len(nums)
        ans = n+1
        left = sum = 0
        for i in range(n):
            sum += nums[i]
            while sum >= s:
                ans = min(ans, i+1-left)
                sum -= nums[left]
                left += 1
        return ans if ans != n+1 else 0