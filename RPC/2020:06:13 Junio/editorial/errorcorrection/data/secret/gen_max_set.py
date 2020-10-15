#!/usr/bin/env python3

# make a randomized attempt to generate a maximal set where which is swap-free

import random
import argparse
import string

import errorcorrection_library

p = argparse.ArgumentParser()
p.add_argument('num_letters', type=int)
args = p.parse_args()

w = string.ascii_lowercase[:args.num_letters]

words = {errorcorrection_library.gen_word(w)}

MAX_WORDS = 5000
attempts = 0
while attempts < 10000 and len(words) < MAX_WORDS:
    attempts += 1

    s = errorcorrection_library.gen_word(w)

    if s in words:
        continue

    for x in words:
        if not errorcorrection_library.admissable(s, x):
            break
    else:
        words.add(s)
        attempts = 0

print(len(words))
for w in words:
    print(w)

