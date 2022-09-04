import sys
input = sys.stdin.readline
# print = sys.stdout.write

_n = int(input())
list = []
for i in range(_n):
    d = int(input())
    list.append(d)

sorted = [ 0 ] * 8001
for n in list:
    sorted[n + 4000 ] += 1

ans = 0
for idx, n in enumerate(sorted):
    ans += (idx - 4000) * n

print( round(ans / _n) )

mid = _n // 2 + (1 if _n%2 else 0)
for idx, n in enumerate(sorted):
    mid -= n
    if mid <= 0 :
        print( idx - 4000 )
        break

mx = 0
for idx, n in enumerate(sorted):
    if mx < n:
        mx = n

non = 0
cnt = 2
for idx, n in enumerate(sorted):
    if n == mx:
        cnt -= 1
        non = idx
        if cnt == 0:
            print( idx - 4000 )
            break

if cnt == 1:
    print( non - 4000 )

mx = 8000
mn = 0
while mx >= 0:
    if sorted[mx] > 0:
        break
    mx -= 1

while mn <= 8000:
    if sorted[mn] > 0:
        break
    mn += 1

print(mx - mn)