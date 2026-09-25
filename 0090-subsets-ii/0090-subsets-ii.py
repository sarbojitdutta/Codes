class Solution:
    def subsetsWithDup(self, nums: list[int]) -> list[list[int]]:
        result = []
        def backtrack(current, index):
            nums.sort()
            if index == len(nums):
                return result.append(current.copy())

            current.append(nums[index])
            backtrack(current, index + 1)

            current.pop()
            idx = index + 1
            while idx < len(nums) and nums[idx] == nums[idx - 1]:
                idx += 1
            
            backtrack(current, idx)
        backtrack([], 0)

        return result
            
            
