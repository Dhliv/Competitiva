a, b = map(int, input().split())
ops = 0
while a > b:
    ops += 1
    if a % 2 == 0:
        a //= 2
    else:
        a += 1

ops += b - a
print(ops)
