class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums = sorted(nums)
        ans = 5e4

        for i in range(len(nums)):
            j, k = (0, len(nums)-1)

            if j == i:
                j = j+1
            if k == i:
                k = k-1

            while j < k:
                m = nums[i] + nums[j] + nums[k]
                if abs(target-ans) > abs(target-m):
                    ans = m
                
                if m < target:
                    j+=1
                    if j == i:
                        j += 1
                elif m > target:
                    k -= 1
                    if k == i:
                        k -= 1
                else: 
                    break
        
        return ans
