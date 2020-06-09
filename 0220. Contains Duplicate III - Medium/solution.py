class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        if k < 0 or t < 0:
            return False

        bucket = {}

        t += 1
        for i, num in enumerate(nums):
            bucket_id = num // t

            for near_by in (bucket_id-1, bucket_id, bucket_id+1):
                if near_by in bucket and abs(bucket[near_by] - num) < t:
                    return True

            bucket[bucket_id] = num

            if i >= k:
                expired = nums[i - k] // t
                del bucket[expired]

        return False