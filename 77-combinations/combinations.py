class Solution:
    def combine(self, n: int, k: int) -> list[list[int]]:
        result = []

        def getCombine(current, start):
            if len(current) == k:
                return result.append(current.copy())

            for i in range(start, n + 1):
                current.append(i)
                getCombine(current, i + 1)
                current.pop()
            
        getCombine([], 1)
        return result
                
            