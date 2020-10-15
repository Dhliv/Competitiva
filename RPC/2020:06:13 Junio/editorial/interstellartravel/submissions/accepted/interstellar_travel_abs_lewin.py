#!/usr/bin/python3
import math
FULL_CIRCLE = 2.0 * math.pi

n = int(input())
stars = []
# t_i s_i, a_i
for i in range(n):
    stars.append(list(map(float, input().split())))

bvalue = 0
bangle = 0
cvalue = 0
for t,s,a in stars:
    cvalue += max(0, t - s * min(a, FULL_CIRCLE - a))
bvalue = cvalue

cslope = 0

evts = []
for t,s,a in stars:
    center = a
    length = t / s
    evts.append((center, - 2 * s))
    if length >= FULL_CIRCLE / 2:
        if center >= FULL_CIRCLE / 2:
            cslope -= s
            evts.append((center - FULL_CIRCLE / 2, +2 * s))
        else:
            cslope += s
            evts.append((center + FULL_CIRCLE / 2, +2 * s))
    else:
        first = center - length
        second = center + length
        if first < 0: first += FULL_CIRCLE
        if second >= FULL_CIRCLE: second -= FULL_CIRCLE
        evts.append((first, +s))
        evts.append((second, +s))
        cm = min(first,second,center)
        if cm == center:
            cslope += s
        elif cm == second:
            cslope -= s
        elif cm == first:
            pass
        else:
            raise RuntimeError()

evts = sorted(evts)
last = 0
for ca, ch in evts:
    cvalue += cslope * (ca - last)
    if cvalue > bvalue:
        bvalue = cvalue
        bangle = ca 
    cslope += ch
    last = ca

print("%.10f\n" % bvalue)
# print("%.10f\n" % bangle)
