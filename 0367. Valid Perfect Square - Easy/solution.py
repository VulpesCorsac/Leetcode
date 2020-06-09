class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        # Newton's method
        r = num
        while r*r > num:
            r = (r + num / r) // 2
        return r*r == num