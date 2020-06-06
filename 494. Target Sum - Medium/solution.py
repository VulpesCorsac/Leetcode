class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        if not nums or S > 1000:
            return 0
        
        dic = {nums[0]: 1, -nums[0]: 1} if nums[0] else {0: 2}
        
        for i in range(1, len(nums)):
            tdic = {}
            
            for d in dic:
                tdic[d + nums[i]] = tdic.get(d + nums[i], 0) + dic.get(d, 0)
                tdic[d - nums[i]] = tdic.get(d - nums[i], 0) + dic.get(d, 0)
            
            dic = tdic
        
        return dic.get(S, 0)