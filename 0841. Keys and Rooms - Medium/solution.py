class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        seen = [False] * len(rooms)
        seen[0] = True
        to_visit = [0]
        while to_visit:
            room = to_visit.pop()
            for neighbor in rooms[room]:
                if not seen[neighbor]:
                    seen[neighbor] = True
                    to_visit.append(neighbor)
        return all(seen)