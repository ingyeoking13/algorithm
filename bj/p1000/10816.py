import sys
input = sys.stdin.readline
n = int(input())
l = list(map(int, input().split()))
d = {}
for i in l:
    cnt = d.get(i, 0)
    d[i] = cnt + 1

m = int(input())
l = list(map(int, input().split()))
for i in l:
    cnt = d.get(i, 0)
    print(cnt, end=' ')

