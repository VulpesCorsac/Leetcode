class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        prefix = {0: -1}
        best_till = [math.inf] * len(arr)
        ans = best = math.inf
        for i, total in enumerate(itertools.accumulate(arr)):
            if total-target in prefix:
                end = prefix[total-target]
                if end > -1:
                    ans = min(ans, i-end+best_till[end])
                best = min(best, i-end)
            best_till[i] = best
            prefix[total] = i
        return -1 if ans == math.inf else ans