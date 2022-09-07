import sys
input = sys.stdin.readline
n = list(map(int, input().split()))
a = set(list(map(int, input().split())))
b = set(list(map(int, input().split())))
c = (a - b) | (b-a)
print(len(c))
