#!/usr/bin/env python3
import itertools
r,c,a,b = map(int, input().split())
arr = list(int(input()) for _ in range(a)) ;
brr = list(int(input()) for _ in range(b)) ;

s1 = "".join(map(lambda x: x[0]*x[1], zip(brr, itertools.cycle("BW"))))
s2 = "".join(map(lambda x: x[0]*x[1], zip(brr, itertools.cycle("WB"))))
for ai in arr:
    print("\n".join([s1]*ai))
    s1,s2 = s2,s1
