cnt = 0

def fibonacci(n):
    global cnt
    f = [0]*(n+1)
    f[1] = f[2] = 1
    for i in range(3, n+1):
        cnt += 1
        f[i] = f[i - 1] + f[i - 2]
    return f[n]

n =int(input())
fibonacci(n)
tmp = cnt
print(f'{fibonacci(n)} {tmp}')