class Solution:
    def myAtoi(self, str: str) -> int:
        str = str.strip();
        str = re.findall('(^[\+\-0]*\d+)\D*', str)

        MAX, MIN = 2**31 - 1, -2**31
        try:
            res = int("".join(str))
            return max(min(res, MAX), MIN)
        except:
            return 0