#!/usr/bin/env python2

# compute the three types of events for each "star", which arrive in this
# order (by angle):
#   - enter: the star just started contributing to the ship
#   - middle: the ship is perfectly aligned with the star
#   - leave: the star just finished contributing to the ship
#
# sort the events by angle, then try each one -- it's sufficient to try each
# one of these; we don't need something between events
#
# keep sufficient statistics on the contributions of t, s, and s*a so that we
# can efficiently compute the distance for this angle
#
# runtime: O(n log n) for the sort

import math
import sys

# Compute the low/high angles where the value goes to zero
#     0 = t - s * |a - angle|
#     t = s * |a - angle|
#     t/s = |a - angle|
#     t/s = a - angle       or  t/s = angle - a
#     angle = a - t/s       or  angle = a + t/s
def low(star):
    t, s, a = star
    return a - t/s

def high(star):
    t, s, a = star
    return a + t/s

def main():
    n = int(sys.stdin.readline())
    stars = [tuple(map(float, sys.stdin.readline().split())) for _ in range(n)]

    ENTER = 0
    MIDDLE = 1
    LEAVE = 2

    events = [(low(s),  i, ENTER)   for i, s in enumerate(stars)] + \
             [(s[-1],   i, MIDDLE) for i, s in enumerate(stars)] + \
             [(high(s), i, LEAVE)   for i, s in enumerate(stars)]
    events.sort()

    # for those where we're approaching the angle:
    # t1 - s1 * (a1 - angle)
    # t2 - s2 * (a2 - angle)
    #...
    # v_approaching = sum(ti) - sum(si * ai) + angle * sum(si)
    #
    # for those where we've passed the angle:
    # v_passed = sum(ti) + sum(si * ai) - angle * sum(si)
    #
    # ignoring the sum(ti) and sum(si * ai) terms (which are constant), we have
    #
    #   max_{last_event <= angle <= next_event} [ angle * (sum_{approaching}(si) - sum_{passed}(si)) ]
    #
    # which is maximized at one of the two event endpoints; so it is sufficient
    # to just check each event

    sum_t = sum_sa = sum_s = distance = best_distance = 0

    for angle, i, kind in events:
        t, s, a = stars[i]
        sa = s * a
        if kind == ENTER:
            sum_t += t
            sum_sa -= sa
            sum_s += s
            distance = sum_t + sum_sa + angle * sum_s
        elif kind == MIDDLE:
            sum_sa += sa
            sum_s -= s
            distance = sum_t + sum_sa + angle * sum_s
            sum_sa += sa
            sum_s -= s
        elif kind == LEAVE:
            sum_t -= t
            sum_sa -= sa
            sum_s += s
            distance = sum_t + sum_sa + angle * sum_s

        best_distance = max(distance, best_distance)

    print('{:0.10f}'.format(best_distance))

if __name__ == '__main__':
    main()

