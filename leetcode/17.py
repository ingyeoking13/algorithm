class Solution:
    d = {
        2 : 'abc', 3 : 'def',
        4 : 'ghi', 5 : 'jkl',
        6 : 'mno', 7 : 'pqrs',
        8 : 'tuv', 9 : 'wxyz'
    }
    def __init__(self):
        self.ans = []

    def go(self, digits: str, idx: int, cur: str):
        if idx == len(digits):
            if cur == "":
                return
            self.ans.append(cur)
            return
        
        print(idx, cur)
        
        for c in self.d[int(digits[idx])]:
            self.go(digits, idx+1, cur+c)

    def letterCombinations(self, digits: str) -> List[str]:
        self.go(digits, 0, "")

        return self.ans