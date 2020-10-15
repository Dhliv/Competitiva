#!/usr/bin/env python3

# support library for generators

import random
import string

def gen_word(s):
    w = list(s)
    random.shuffle(w)
    return ''.join(w)

def one_swap(s):
    w = list(s)
    i, j = random.sample(range(len(s)), 2)
    w[i], w[j] = w[j], w[i]
    return ''.join(w)

def num_swaps(a, b):
    return sum(ai != bi for ai, bi in zip(a, b))

def admissable(a, b):
    return num_swaps(a, b) not in (0, 2)

def parity(s):
    p = False
    for i, si in enumerate(s):
        for j, sj in enumerate(s[i+1:], i+1):
            if sj < si:
                p = not p
    return p

