#!/usr/bin/env python3

# make a randomized attempt to generate a maximal set which is swap free and
# has the same parity and one other word which is swappable with all (or many
# of) the first group.

import random
import argparse
import string

import errorcorrection_library

p = argparse.ArgumentParser()
p.add_argument('num_letters', type=int)
args = p.parse_args()

# we could start with 'abcde...' but shuffle the word a bit, maintaining parity
# 0
start = errorcorrection_library.gen_word(random.sample(string.ascii_lowercase, args.num_letters))
while errorcorrection_library.parity(start):
    start = errorcorrection_library.gen_word(start)
assert not errorcorrection_library.parity(start)

words = {start}

MAX_WORDS = 5000
attempts = 0
while attempts < 10000 and len(words) < MAX_WORDS:
    attempts += 1

    s = errorcorrection_library.one_swap(start)
    assert errorcorrection_library.parity(s)

    if s in words:
        continue

    words.add(s)
    attempts = 0

print(len(words))
words = list(words)
random.shuffle(words)
for w in words:
    print(w)

