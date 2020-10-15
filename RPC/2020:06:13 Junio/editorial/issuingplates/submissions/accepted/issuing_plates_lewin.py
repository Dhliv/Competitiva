#!/usr/bin/env python3
n,m = map(int, input().split())
d = {"0":"O","1":"L","2":"Z","3":"E","5":"S","6":"B","7":"T","8":"B"}
s = set([input() for __ in range(n)])

def f(x):
    for k,v in d.items():
        x = x.replace(k,v)
    return x

for _ in range(m):
    g = f(input())
    print("INVALID" if any(w in g for w in s) else "VALID")
