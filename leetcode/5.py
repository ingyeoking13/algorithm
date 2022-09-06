class Solution:
    def ispalindrom(self, i:int, j:int, s: str) -> bool:
        
        while i < j:
            if s[j] != s[i]:
                return False
            i+=1
            j-=1
            
        return True
    
    def longestPalindrome(self, s: str) -> str:
        mx = 1
        f = 0
        t = 0
        
        i = 0
        while i < len(s):
            j = i + mx
            while j < len(s):
                if self.ispalindrom(i, j, s):
                    if mx < j-i+1:
                        f = i
                        t = j
                        mx = j-i+1
                        
                j+=1
            i+=1
            
        return s[f:t+1]
            