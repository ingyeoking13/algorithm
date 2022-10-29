class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        s = set()
        for i in nums:
            if i in s:
                return i
            s.add(i)