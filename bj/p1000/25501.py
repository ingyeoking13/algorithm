def recursion(s, l, r, cnt):
    if l >= r: return (1, cnt)
    elif s[l] != s[r]: return (0, cnt)
    return recursion(s, l+1, r-1, cnt+1)

def isPalindrome(s):
    return recursion(s, 0, len(s)-1, 1)


n = int(input())
for i in range(n):
    s = input()
    a, b = isPalindrome(s)
    print(f'{a} {b}')