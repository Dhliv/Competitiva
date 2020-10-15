#!/usr/bin/env python3

# Use the property that (a + 1) * (b + 1) * (c + 1) * ... * (z + 1) gives the
# sum of all monomials, where each monomial is a combination of between 0 and
# all of the variables (a-z). Sneaky.

import string
import functools
import sys

MOD = 11092019

s = sys.stdin.readline().strip()
counts = [s.count(c) + 1 for c in string.ascii_lowercase if s.count(c)]
p = functools.reduce(lambda a, b: a * b, counts) # NB: computes the full answer before mod
print(p % MOD)

