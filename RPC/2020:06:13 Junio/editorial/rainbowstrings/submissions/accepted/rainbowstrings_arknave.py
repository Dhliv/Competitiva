#!/usr/bin/env python3
from collections import Counter

MOD = 11092019

c = Counter(input())
ans = 1
for _, freq in c.items():
    ans = ans * (freq + 1) % MOD

print(ans)
