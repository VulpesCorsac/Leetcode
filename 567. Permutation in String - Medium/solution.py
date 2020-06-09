class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        s1_map = [0] * 26
        s2_map = [0] * 26

        for i in range(len(s1)):
            s1_map[ord(s1[i]) - ord('a')] += 1
            s2_map[ord(s2[i]) - ord('a')] += 1

        cnt = 0
        for i in range(26):
            if s1_map[i] == s2_map[i]:
                cnt += 1

        for i in range(len(s2) - len(s1)):
            r = ord(s2[i + len(s1)]) - ord('a')
            l = ord(s2[i          ]) - ord('a')

            if cnt == 26:
                return True

            s2_map[r] += 1;
            if s2_map[r] == s1_map[r]:
                cnt += 1
            elif s2_map[r] == s1_map[r] + 1:
                cnt -= 1

            s2_map[l] -= 1
            if s2_map[l] == s1_map[l]:
                cnt += 1
            elif s2_map[l] == s1_map[l] - 1:
                cnt -= 1

        return cnt == 26