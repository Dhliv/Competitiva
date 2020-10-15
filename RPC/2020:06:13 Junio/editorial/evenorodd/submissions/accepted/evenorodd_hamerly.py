#!/usr/bin/env python3

import sys

n = int(sys.stdin.readline())

even = odd = False

for i in range(1, 101 - n):
    s = sum(range(i, i + n))
    
    if (s % 2) == 0:
        even = True
    else:
        odd = True

if even and odd:
    print('Either')
elif even:
    print('Even')
else:
    print('Odd')
