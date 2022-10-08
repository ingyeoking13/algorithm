def get_cnt(base, val):
    ans = 0
    while val >= base:
        ans += val//base
        val //= base
    return ans

n, m= list(map(int,input().split()))

ans_2 = get_cnt(2, n) - get_cnt(2, m) - get_cnt(2, n-m)
ans_5 = get_cnt(5, n) - get_cnt(5, m) - get_cnt(5, n-m)
print(min(ans_2, ans_5))
