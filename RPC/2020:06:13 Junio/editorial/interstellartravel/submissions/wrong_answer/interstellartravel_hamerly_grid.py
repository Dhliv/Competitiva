#!/usr/bin/env python3

# grid search; probably too inaccurate; definitely slow for large n

import math
import sys

def get_angle(low, high, i, grid_division):
    return (high - low) * (i + 0.5) / grid_division + low

def value(stars, angle):
    v = 0.0
    for t, s, a in stars:
        delta = abs(a - angle)
        if delta > math.pi:
            delta = 2.0*math.pi - delta
        sv = t - s * abs(a - angle)
        v += sv if 0 < sv else 0
    return v

def main():
    n = int(sys.stdin.readline())
    stars = [tuple(map(float, sys.stdin.readline().split())) for _ in range(n)]

    grid_division = 10 # how finely to search each range
    search_arity = 5 # shrink the range by 2/search_arity each step

    low = 0
    high = 2 * math.pi
    eps = 1e-8

    # running time is O(n * g * e)
    # where n is the number of stars
    #       g is the grid_division
    #       e = log(eps) / (log(2) - log(search_arity))

    while low + eps <= high:
        #sys.stderr.write("{} {}".format(low, high))
        best_i = 0
        best_v = value(stars, get_angle(low, high, 0, grid_division))
        for i in range(1, grid_division + 1):
            v = value(stars, get_angle(low, high, i, grid_division))
            if best_v < v:
                best_v = v
                best_i = i

        new_mid = get_angle(low, high, best_i, grid_division)
        new_low = max(0, new_mid - (high - low) / search_arity)
        new_high = min(2 * math.pi, new_mid + (high - low) / search_arity)
        #print('low {low} high {high} best_i {best_i} new_low {new_low} new_high {new_high}'.format(**locals()))
        low, high = new_low, new_high

    print('{:0.10f}'.format(value(stars, low)))

if __name__ == '__main__':
    main()

