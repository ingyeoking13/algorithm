n = int(input())
dir = [4, 2, 3, 1]

l = []
inverted_width = 0
d = {}
for i in range(6):
    _dir, _len = list(map(int, input().split()))
    l.append((_dir,_len))
    d[_dir] = max(d.get(_dir, 0), _len)

prev = l[0][0]
for i in range(1, 12):
    _i = i%6
    _next = l[_i][0]
    if (dir.index(prev) + 1)%4 == dir.index(_next):
        prev = _next
        continue
    else: 
        inverted_width = l[_i][1]*l[_i-1][1]
        break

w = max(d[3],d[4]) 
h = max(d[1],d[2]) 
width = w*h-inverted_width
print(width*n)
