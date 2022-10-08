W, H, X, Y, P = list(map(int,input().split()))

cnt = 0
for i in range(P):
    check = False
    x, y = list(map(int, input().split()))
    r = H/2
    if x >= X and y >= Y and x <= X+W and y <= Y+H:
        check = True
    if (x-X)*(x-X) + (y-r-Y)*(y-r-Y) <= r*r:
        check = True
    if (x-W-X)*(x-W-X) + (y-r-Y)*(y-r-Y) <= r*r:
        check = True
    if check:
        cnt+=1

print( cnt )