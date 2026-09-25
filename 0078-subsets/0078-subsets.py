class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:
        result = []

        def backtrack(current, i):
            if i == len(nums):
                result.append(current.copy())
                return
            
            current.append(nums[i])
            backtrack(current, i + 1)
            
            current.pop()
            backtrack(current, i + 1)

        backtrack([], 0)

        return result
    