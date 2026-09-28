class Solution:
    def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:
        result = []
        candidates.sort()

        def getCombinesum(current, index, target):
            if target == 0:
                return result.append(current.copy())

            
            if index == len(candidates) or target < 0:
                return
                    
            for i in range(index, len(candidates)):
                if i > index and candidates[i] == candidates[i - 1]:
                    continue
                
                current.append(candidates[i])
                getCombinesum(current, i + 1, target - candidates[i])
                current.pop()

        getCombinesum([], 0, target)
        return result

        