import sys
input = sys.stdin.readline

_n = int(input())
l = [ int(input()) for _ in range(_n) ]

print( round(sum(l)/len(l)) )

sorted = [ f for f in l ]
sorted.sort()
print( sorted[_n//2] )

f = { }
d = 0
for i in l:
    s = f.get(i, 0)
    f[i] = s + 1
    if d < f[i]:
        d = f[i]

d = [ i for i, j in f.items() if j == d]
d.sort()
if len(d) > 1:
    d = d[1]
else:
    d = d[0]
print(d)

print(sorted[_n-1]-sorted[0])