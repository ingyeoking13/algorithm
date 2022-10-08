import sys
input = sys.stdin.readline
n, k = list(map(int, input().split()))
_v = list(map(int,input().split()))
ans = -1

def merge_sort(v, i, j):
    if i < j:
        m = (i+j)//2 
        merge_sort(v, i, m)
        merge_sort(v, m+1, j)
        merge(v, i, m+1, j)

def merge(v, i, m, j):
    global k
    global ans
    p = i
    q = m
    r = 0
    temp = [0] * (j-i+1)
    while p < m and q <= j:
        k-=1
        if v[p] > v[q]:
            temp[r] = v[q]
            q+=1
        else:
            temp[r] = v[p]
            p+=1
        if k == 0:
            ans = temp[r]
        r+=1
    
    while p < m:
        temp[r] = v[p]
        k-=1
        if k == 0:
            ans = temp[r]
        p+=1
        r+=1
    
    while q <= j:
        temp[r] = v[q]
        k-=1
        if k == 0:
            ans = temp[r]
        q+=1
        r+=1
    
    p=i
    i=0
    while p<=j:
        v[p] = temp[i]
        p+=1
        i+=1
    
merge_sort(_v, 0, n-1)
print(ans)