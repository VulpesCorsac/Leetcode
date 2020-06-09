class Solution:
    def majorityElement(self, nums):
        cnt = 0
        ans = None

        for item in nums:
            if cnt == 0:
                ans = item
            cnt += (1 if item == ans else -1)

        return ans


class Solution2:
    def majorityElement(self, nums: List[int]) -> int:
      nums.sort()
      return nums[len(nums)//2]