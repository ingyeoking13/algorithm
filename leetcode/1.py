class Solution(object):
    def twoSum(self, nums, target):
        d:dict = {}
        res = None
        for i in range(0, len(nums)): 
            cur = nums[i]
            if d.get(target - cur) is not None: res = [d[target-cur], i]
            d[cur] = i
            if res: break
        return res


sol = Solution()
print( sol.twoSum([3,2,4,15], 6) )

