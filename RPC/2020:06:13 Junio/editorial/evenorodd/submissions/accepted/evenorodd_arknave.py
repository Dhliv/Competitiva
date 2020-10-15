#!/usr/bin/env python3
n = int(input())
even, odd = False, False
for l in range(1, 100 - n):
    s = sum(l + i for i in range(n))
    if s % 2 == 0:
        even = True
    else:
        odd = True

if even and odd:
    print('Either')
elif even:
    print('Even')
elif odd:
    print('Odd')
else:
    assert(False)
