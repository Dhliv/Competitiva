#!/usr/bin/env python3

# slow DP

import string
import sys

# DP, probably should be TLE due to the 2^26 factor
# runtime: O(n + 2^k * k^2), where k <= 26 is the number of unique characters

MOD = 998244353

s = sys.stdin.readline().strip()
counts = [s.count(c) for c in string.ascii_lowercase if s.count(c)]

lengths = [(1, 0)] # count, start ndx
total = 1

for length in range(1, len(counts) + 1):
    new_lengths = []
    for count, start in lengths:
        for i, c in enumerate(counts[start:], start):
            a = (c * count) % MOD
            new_lengths.append((a, i + 1))
            total += a
    lengths = new_lengths
    total %= MOD

print(total)

