#!/usr/bin/env python3

import sys

def main():
    n = int(sys.stdin.readline())
    taxes = list(map(int, sys.stdin.readline().split()))
    tree = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v, w = map(int, sys.stdin.readline().split())
        u -= 1
        v -= 1
        tree[u].append((v, w))
        tree[v].append((u, w))

    preorder = []
    par = [-1 for _ in range(n)]
    depth = [0 for _ in range(n)]
    stk = [(0, -1)]
    while stk:
        u, p = stk.pop()
        preorder.append(u)
        for v, w in tree[u]:
            if v == p:
                continue
            par[v] = u
            depth[v] = depth[u] + w
            stk.append((v, u))

    sizes = [1 for _ in range(n)]
    tax_sums = list(taxes)
    for u in reversed(preorder):
        for v, w in tree[u]:
            if v == par[u]:
                continue

            sizes[u] += sizes[v]
            tax_sums[u] += tax_sums[v]

    sum_dist = sum(depth)
    sum_tax_dist = sum(taxes[u] * depth[u] for u in range(n))
    stk = [(0, sum_dist, sum_tax_dist)]
    ans = [0 for _ in range(n)]
    while stk:
        u, a, b = stk.pop()
        ans[u] = (b + taxes[u] * a)
        for v, w in tree[u]:
            if v == par[u]:
                continue
            na = a - w * sizes[v] + w * (n - sizes[v])
            nb = b - w * tax_sums[v] + w * (tax_sums[0] - tax_sums[v])
            stk.append((v, na, nb))

    for d in ans:
        print(d)

if __name__ == '__main__':
    main()
