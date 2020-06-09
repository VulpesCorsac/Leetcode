class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        A = {u: i for i, u in enumerate(list1)}
        best, ans = 1e9, []

        for j, v in enumerate(list2):
            i = A.get(v, 1e9)
            if i + j < best:
                best = i + j
                ans = [v]
            elif i + j == best:
                ans.append(v)
        return ans