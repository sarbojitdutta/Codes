class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        dict = {}
        for i in range(0, len(nums)):
            y = target - nums[i]

            for index, value in dict.items():
                if value == y:
                    return [index, i]

            dict[i] = nums[i]
        
        return []
