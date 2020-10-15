n = int(input())
old = tuple(map(int, input().split()))
ans = 0
for _ in range(n - 1):
    cur = tuple(map(int, input().split()))
    ans = max(ans, (cur[1] - old[1]) // (cur[0] - old[0]))
    old = cur

print(ans)
