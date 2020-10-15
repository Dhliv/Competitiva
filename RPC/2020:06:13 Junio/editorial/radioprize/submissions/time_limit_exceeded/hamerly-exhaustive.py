#!/usr/bin/env python3

# try DFS from every node

import sys

def main():
    # read input, construct the tree
    ri = lambda: tuple(map(int, sys.stdin.readline().split()))
    n, = ri()
    taxes = ri()
    tree = [[] for _ in range(n)]
    for _ in range(n-1):
        u, v, w = ri()
        u, v = u - 1, v - 1
        tree[u].append((v, w))
        tree[v].append((u, w))

    for start in range(n):
        answer = 0
        stack = [(start, -1, 0)] # (current, predecessor, depth)
        while stack:
            u, p, depth = stack.pop()
            answer += (taxes[start] + taxes[u]) * depth
            for v, w in tree[u]:
                if v == p: # don't go back up the tree
                    continue
                stack.append((v, u, depth + w))

        print(answer)

if __name__ == '__main__':
    main()

