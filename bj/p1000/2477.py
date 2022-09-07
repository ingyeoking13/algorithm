n = int(input())

a = {}
b = []
for i in range(6):
    d, l = list(map(int, input().split()))
    if a.get(d, -1) == -1:
        a[d] = l
    else:
        if a[d] < l:
            b.append(a[d])
            a[d] = l
        else:
            b.append(l)

w = max(a[1], a[2]) * max(a[3], a[4])
print((w - b[0]* b[1])*n)
