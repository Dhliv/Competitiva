#!/usr/bin/env python3

import argparse
import random
import math

p = argparse.ArgumentParser()
p.add_argument('--falloff', type=float, default=1.0)
p.add_argument('--sigma', type=float, default=0.1)
p.add_argument('--groups', type=int, default=1)
p.add_argument('-n', type=int, default=1000000)
p.add_argument('--seed', type=int, default=42)
args = p.parse_args()

random.seed(args.seed)

group_centers = [random.uniform(0, 2 * math.pi) for _ in range(args.groups)]

def wrap_angle(a):
    return a % (math.pi * 2)

with open('rand_n_{n}_groups_{groups}_sigma_{sigma:0.2f}_falloff_{falloff:0.2f}_seed_{seed}.in'.format(**vars(args)), 'w') as out:
    out.write('{}\n'.format(args.n))
    for _ in range(args.n):
        t = random.uniform(0.00001, 1000)
        s = min(max(0, random.uniform(0, 100) * args.falloff), 100)
        c = random.choice(group_centers)
        a = wrap_angle(random.normalvariate(c, args.sigma))
        out.write('{:0.6f} {:0.6f} {:0.6f}\n'.format(t, s, a))


