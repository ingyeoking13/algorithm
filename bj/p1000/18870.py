import sys
input = sys.stdin.readline
n = input()
list = list(map(int, input().split()))
sorted = [i for i in list]
sorted.sort()

d = {}
idx = 0
for i in range(int(n)):
    t = d.get(sorted[i], -1)
    if t == -1:
        t = idx
        idx += 1
    d[sorted[i]] = t

for i in list:
    print(d[i],end=' ')
