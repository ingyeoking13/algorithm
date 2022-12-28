class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        answer = strs[0]

        for target in range(1,len(strs)):
            i, j = (0, 0)
            while i < len(answer) and j < len(strs[target]):
                if answer[i] == strs[target][j]:
                    i+=1
                    j+=1
                else:
                    break
            answer = answer[:i]
        
        return answer