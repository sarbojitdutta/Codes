class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        dict = {}
        for i in range(0, len(nums)):
            y = target - nums[i]

            if y in dict:
                return [dict[y], i]
            dict[nums[i]] = i
        
        return []
