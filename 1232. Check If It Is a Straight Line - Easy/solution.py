class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        if len(coordinates) > 2:
            p0 = coordinates[0]
            p1 = coordinates[1]
            for p in coordinates[2:]:
                if p0[0] * (p1[1] - p[1]) + p1[0] * (p[1] - p0[1]) + p[0] * (p0[1] -p1[1]) != 0:
                    return False

        return True