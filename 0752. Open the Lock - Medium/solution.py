class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        deadends = set(deadends)
        positions = ["0000"]
        moves = 0
        move = {str(i): [str((i + 1) % 10), str((i - 1) % 10)] for i in range(10)}

        if "0000" in deadends:
            return -1

        while positions:
            next = []
            moves += 1
            for position in positions:
                for i, digit in enumerate(position):
                    for current in (position[:i] + move[digit][0] + position[i+1:], position[:i] + move[digit][1] + position[i+1:]):
                        if current not in deadends:
                            if current == target:
                                return moves
                            next.append(current)
                            deadends.add(current)
            positions = next

        return -1