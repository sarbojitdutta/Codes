class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        stack = []

        results = ""

        for ch in s:
            if ch == '(':
                stack.append(ch)

                if len(stack) > 1:
                    results += ch

            else:
                stack.pop()

                if len(stack) > 0:
                    results += ch

        return results



        
        