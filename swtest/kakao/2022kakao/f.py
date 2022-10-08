from typing import Tuple, List
from queue import Queue

dx = [1, 0, 0, -1]
dy = [0, -1, 1, 0]
dir = ['d', 'l', 'r', 'u']

def _dist(f:Tuple[int,int], t:Tuple[int,int]):
    return abs((f[0]-t[0])+ (f[1]- t[1]))

def solution(n, m, x, y, r, c, k):
    d:int = _dist((x,y), (r, c))
    diff:int= abs(d-k)
    print(diff)
    if diff%2:
        return 'impossible'
    sx= x-1
    sy= y-1

    ex = r-1
    ey = c-1
    answer = ""
    x = sx
    y = sy

    while x + 1 < n and diff:
        print('a')
        answer += "d"
        x+=1
        diff -= 1
    while y -1 >= 0 and diff:
        print('b')
        answer += "l"
        y-=1
        diff -= 1
    while y + 1 < m and diff:
        print('c')
        answer += "r"
        x += 1
        diff -= 1
    while x - 1 >= 0 and diff:
        print('d')
        answer += "u"
        y += 1
        diff -= 1


    visit:List[List[bool]] = [[False]*m]*n
    route = [['']*m]*n
    q = Queue()
    q.put((x, y, 0))
    while( not q.empty() ): 
        x,y,dist = q.get()

        if dist >= diff:
            continue

        if x == ex and y == ey:
            break

        for i in range(4):
            nx = x+ dx[i]
            ny = y+ dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            if visit[nx][ny]:
                continue
            visit[nx][ny] = True
            route[nx][ny] = dir[i]
            q.put((nx, ny, dist+1))

    x, y= (ex, ey)
    temp = ""
    while True:
        temp += route[x][y]
        c = route[x][y]
        if c == 'd': x = x-1
        elif c == 'l': y = y+1
        elif c == 'r': y = y-1
        elif c == 'u': x = x+1
        if x == sx and y == sy:
            break
    temp = answer[::-1]
    answer = answer + temp

    return answer


# solution(3, 4, 2, 3, 3, 1, 5)
# solution(2, 2, 1, 1, 2,2,2)
# solution(3, 3, 1, 2, 3, 3, 4)
# solution(2, 1, 1, 1, 2, 1, 3)
solution(1, 2, 1, 1, 1, 2, 3)