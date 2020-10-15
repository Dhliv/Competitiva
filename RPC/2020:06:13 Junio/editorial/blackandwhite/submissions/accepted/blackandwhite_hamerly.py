#!/usr/bin/env python3

import sys

bad = lambda r: int('BBB' in r or 'WWW' in r or r.count('W') != r.count('B'))

n = int(sys.stdin.readline())
grid = [sys.stdin.readline().strip() for _ in range(n)]
gridT = [''.join(grid[j][i] for j in range(n)) for i in range(n)]

ans = 0 if sum(map(bad, grid + gridT)) else 1
print(ans)

