class Solution:
    def calculate(self, s: str) -> int:
        if not s:
            return 0
        
        stack, curr, ops = [], 0, "+"
        all_ops = {"+", "-", "/", "*"}

        for index in range(len(s)):
            char = s[index]

            if char.isdigit():
                curr = curr * 10 + int(char)
            if char in all_ops or index == len(s) - 1:
                if ops == "+":
                    stack.append(curr)
                elif ops == "-":
                    stack.append(-curr)
                elif ops == "*":
                    stack[-1] *= curr
                elif ops == "/":
                    stack[-1]  = int(stack[-1] / curr)
                
                curr = 0
                ops = char

        return sum(stack)
            


        