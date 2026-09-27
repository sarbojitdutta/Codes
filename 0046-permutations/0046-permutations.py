class Solution:
    def permute(self, nums: list[int]) -> list[list[int]]:
        result = []

        def getPermute(nums, index):
            if index == len(nums):
                return result.append(nums.copy())

            for i in range(index, len(nums)):
                nums[index], nums[i] = nums[i], nums[index]
                getPermute(nums, index+1)
                nums[index], nums[i] = nums[i], nums[index]
            
        getPermute(nums, 0)
        return result