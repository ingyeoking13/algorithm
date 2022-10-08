sx = set()
sy = set()
for i in range(3):
    x, y = input().split()
    if x in sx:
        sx.remove(x)
    else:
        sx.add(x)
    if y in sy:
        sy.remove(y)
    else:
        sy.add(y)

print(list(sx)[0], list(sy)[0])