class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums.sort()

        expected = 1

        for num in nums:
            if num == expected:
                expected += 1
            elif num > expected:
                break
        return expected

        