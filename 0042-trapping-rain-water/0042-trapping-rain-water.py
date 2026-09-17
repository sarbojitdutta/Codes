class Solution:
    def trap(self, height: list[int]) -> int:
        n = len(height)
        lmax = 0
        rmax = 0
        ans = 0 
        l, r = 0, n-1 

        while l < r:
            lmax = max(lmax, height[l])
            rmax = max(rmax, height[r])

            if lmax < rmax:
                ans += (lmax - height[l])
                l += 1
            else:
                ans += (rmax - height[r])
                r -= 1

        return ans