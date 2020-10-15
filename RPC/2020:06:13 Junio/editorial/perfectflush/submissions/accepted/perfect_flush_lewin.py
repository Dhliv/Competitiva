#!/usr/bin/env python3

from collections import Counter

(n,k) = map(int,input().split())

arr = []
for i in range(n):
   arr.append(int(input()))

rcount = Counter(arr)
lcount = Counter()

res = []
for a in arr:
    rcount[a] -= 1

    if lcount[a] > 0: # remove if at least once
        continue

    while len(res) > 0 and res[-1] > a and (lcount[res[-1]] > 1 or rcount[res[-1]] > 0):
        lcount[res.pop()] -= 1

    res.append(a)
    lcount[a] += 1

while len(res) > 0 and lcount[res[-1]] > 1:
    lcount[res.pop()] -= 1

print(" ".join(map(str,res)))   
