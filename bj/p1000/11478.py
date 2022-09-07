s = input()
se = set()

for i in range(len(s)):
    for j in range(i, len(s)):
        _s = s[i:j+1]
        se.add(_s)

print(len(se))