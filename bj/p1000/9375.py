t = int(input())
for i in range(t):
    n = int(input())
    d = {}
    for j in range(n):
        wear, type = input().split()
        l = d.get(type, [])
        d[type] = [*l, wear]
    
    ans = 1
    for k,v in d.items():
        ans *= (len(v)+1)
    
    ans-=1
    print(ans)
