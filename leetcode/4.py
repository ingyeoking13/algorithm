class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        merged = []
        i = 0
        j = 0
        while i < len(nums1) and j < len(nums2):
            if nums1[i] < nums2[j]:
                merged.append(nums1[i])
                i+=1
            else:
                merged.append(nums2[j])
                j+=1
        
        while i < len(nums1):
            merged.append(nums1[i])
            i+=1
        
        while j < len(nums2):
            merged.append(nums2[j])
            j+=1
       
        
        n = len(merged)
        
        if n%2:
            return merged[n//2]
        
        return (merged[n//2 -1] + merged[n//2])/2
        