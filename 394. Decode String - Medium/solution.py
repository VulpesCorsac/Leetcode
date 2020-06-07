class Solution:
    def decodeString(self, s: str) -> str:
        stack = [] 
        current_number = 0
        current_string = ''
        
        for symbol in s:
            if symbol == '[':
                stack.append(current_string)
                stack.append(current_number)
                current_string = ''
                current_number = 0
            elif symbol == ']':
                number = stack.pop()
                previous_string = stack.pop()
                current_string = previous_string + number * current_string
            elif symbol.isdigit():
                current_number = current_number * 10 + int(symbol)
            else:
                current_string += symbol
        
        return current_string