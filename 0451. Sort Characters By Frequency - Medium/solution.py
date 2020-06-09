from collections import Counter

class Solution(object):
    def frequencySort(self, s):
        c = Counter(s)
        l = []
        for x in sorted(c.items(), key=lambda x: x[1], reverse=True):
            l.append(x[0] * x[1])

        return "".join(l)