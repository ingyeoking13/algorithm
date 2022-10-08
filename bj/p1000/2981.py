def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a%b)

n = int(input())
v = []
for i in range(n):
    v.append(int(input()))
v.sort()
g =  v[1] - v[0]
for i in range(1, n):
    m = v[i] - v[i-1]
    g = gcd(g, m)

ans = []
for i in range(1, g):
    if i*i > g: 
        break
    if g%i > 0:
        continue
    ans.append(i)
    if i != g/i:
        ans.append(g//i)

ans.sort()
for i in ans:
    if i != 1:
        print(i , end= ' ')
