class Solution:
    def intToRoman(self, num: int) -> str:
        d: dict = {
            1: 'I', 5: 'V', 10: 'X', 50: 'L',
            100: 'C', 500: 'D', 1000: 'M'
        }
        s = str(num)
        base = 1
        ans = ''

        for c in reversed(s):
            i = int(c) * base
            dd = d.get(i, '')

            if not dd:
                dd = d[base]
                if int(c) <= 3:
                    dd = d[base]*int(c);
                elif int(c) <= 5:
                    dd = d[base*5] + d[base]
                elif int(c) <= 8: 
                    dd = d[base]*(int(c)-5) + d[base*5] 
                elif int(c) <= 9: 
                    dd = d[base*10] + d[base]  
            
            ans  += dd
            base *= 10

        return ans[::-1]