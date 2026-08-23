class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        
        n = len(arr)
        j = 1

        for i in range(n):
            if arr[i] > arr[j]:
                return i
            else:
                i += 1
                j += 1
            



        