class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        
        f = 0
        t = 1
        d = {}
        
        d[s[f]] = f
        
        ans = 1
        while t < len(s):
            idx = d.get(s[t], -1)
            if idx == -1:
                temp = t - f + 1 
                ans = max(temp, ans)
            else:
                while f <= idx:
                    d[s[f]] = -1
                    f+=1
                    
            d[s[t]] = t
            t+=1
       
        return ans
        
        