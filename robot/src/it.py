'''
0 3 5    1 2 3
4 7 1 -> 4 5 6
8 2 6    7 8 0
'''

import time

def Astar(start,end):
    from heapq import heappush,heappop
    mapping={start:[]}
    node = ((1, 3), (2, 4, 0), (5, 1), (4, 6, 0), (5, 7, 3, 1), (8, 4, 2), (7, 3), (8, 6, 4), (7, 5))
    astar=[]
    heappush(astar,(0,0,start))

    while astar:
        f,g,current=heappop(astar)
        g+=1
        moveing=[move for move in range(len(current))if current[move]=='0']
        for center in moveing:
            for dir in node[center]:
                cur=list(current)
                cur[center],cur[dir]=cur[dir],cur[center]
                h=sum([ 1 if cur[h]!=end[h]else 0 for h in range(len(cur))])
                cur=''.join(cur)

                if cur not in mapping:
                    mapping[cur]=mapping[current][:]
                    mapping[cur].append(current)
                    heappush(astar,(h+g,g,cur))
                if h==0:
                    mapping[cur].append(cur)
                    global answer
                    answer = g
                    return mapping[cur]
sT = time.time()
mapping=Astar('035471826','123456780')
print(answer)
for i in mapping:
    print('==========')
    print(i[0:3])
    print(i[3:6])
    print(i[6:9])
print(time.time() - sT)
'''
==========
035
471
826
==========
435
071
826
==========
435
701
826
==========
435
710
826
==========
430
715
826
==========
403
715
826
==========
413
705
826
==========
413
725
806
==========
413
725
086
==========
413
025
786
==========
013
425
786
==========
103
425
786
==========
123
405
786
==========
123
450
786
==========
123
456
780
0.00800013542175293
'''