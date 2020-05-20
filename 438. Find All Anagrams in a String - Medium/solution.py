class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        letters = [0] * 26
        res = []
        for char in p:
            letters[ord(char) - ord('a')] += 1

        j = 0
        remaining = len(p)

        for i in range(0, len(s)):
            while j < len(s) and j - i < len(p):
                freq = letters[ord(s[j]) - ord('a')]
                if freq > 0:
                    remaining -= 1
                    
                letters[ord(s[j]) - ord('a')] -= 1
                j += 1
            
            index = ord(s[i]) - ord('a')
            
            if remaining == 0 and j - i == len(p):
                res.append(i)
     
            if letters[index] >= 0:
                remaining += 1
            letters[index] += 1
            
        return res