class Solution:
    def findFirst(self, nums: list[int], target: int) -> list[int]:
        low = 0
        high = len(nums)-1
        result = -1

        while low <= high:
            mid = low + (high - low) // 2
            if nums[mid] == target:
                result = mid
                high = mid -1
            elif target < nums[mid]:
                high = mid - 1
            else:
                low = mid + 1
        return result

    def findSecond(self, nums: list[int], target: int) -> list[int]:
        low = 0
        high = len(nums) - 1
        result = -1

        while low <= high:
            mid = low + (high - low) // 2
            if nums[mid] == target:
                result = mid
                low = mid + 1
            elif target < nums[mid]:
                high = mid - 1
            else:
                low = mid + 1
        return result

    def searchRange(self, nums: list[int], target: int) -> list[int]:
        first = self.findFirst(nums, target)
        second = self.findSecond(nums, target)

        return [first, second]
        