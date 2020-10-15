#!/usr/bin/env python3

# This is not a clean-house implementation; I read @arknave's code first.

# after reading arknave's code, I understand a bit better what's going on
#   1. DFS to establish a preorder traversal order
#       - as we go, figure out the "partition" of each node -- in other words,
#       when leaving node u to get to v, then partition[v] == u, because u led
#       directly to v. This helps us later to traverse those things "below" v
#       and not "above" v (in the preorder). I suppose we could do this with
#       some sort of depth numbering too, but that's not as explicit.
#       - keep track of the "depth" as we go -- the cost along all the edges
#       traversed from the root to here. Really a path length.
#
#   2. Do a bottom-up traversal by going in reverse preorder. For each node,
#       - keep track of how many nodes are "beneath" it -- by looking at those
#       that it leads to, plus it (and avoiding those "above" it using the
#       partition earlier established)
#       - also sum up the sum of all taxes of all nodes underneath
#
#   3. DFS from the root again, this time doing the math to compute the answer
#   for each node from the sufficient statistics. Math:
#
#     answer[u] = sum(v != u, dist(u,v) * (tax[u] + tax[v]))
#               = sum(v != u, dist(u,v) * tax[u] + dist(u,v) * tax[v])
#               = tax[u] * sum(v != u, dist(u,v))
#                 + sum(v != u, dist(u,v) * tax[v])
#
#   The important part here is that there are two terms. See the code for
#   how these are actually decomposed and computed using sufficient
#   statistics.

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

    # DFS from (arbitrarily chosen) root 0. For each edge (u,v):
    #   - record the preorder traversal order
    #   - partition the tree by setting u as the back-edge for v
    #   - sum up the path length of all edges along the DFS path
    preorder = []
    previous = [None] * n
    path_length = [0] * n
    stack = [(0, -1)] # (current, predecessor)
    while stack:
        u, p = stack.pop()
        preorder.append(u)
        for v, w in tree[u]:
            if v == p: # don't go back up the tree
                continue
            previous[v] = u # u->v got us here
            path_length[v] = path_length[u] + w
            stack.append((v, u))

    # bottom-up traversal (reverse preorder) to determine sufficient statistics
    # for each subtree:
    #   - how many nodes are at or below this node
    #   - sum of taxes at or below this node
    subtreecount = [1] * n
    subtreetaxsum = list(taxes)
    for u in reversed(preorder):
        for v, w in tree[u]:
            if previous[u] == v:
                continue # don't go "above" u in the tree
            # track how many nodes are at or below u, and the sum of their
            # taxes
            subtreecount[u] += subtreecount[v]
            subtreetaxsum[u] += subtreetaxsum[v]

    # start with sufficient statistics that are correct for the root,
    # corresponding to the two terms needed:
    #   sum(dist(u,v))
    #   sum(dist(u,v) * tax(v)) 
    # and then at each node (as we cross each edge) subtract off the
    # contribution for nodes below, and add a contribution for the nodes above
    # (here above/below is with respect to the preorder).
    stack = [(0, sum(path_length), sum(path_length[u] * taxes[u] for u in range(n)))]
    answer = [0] * n
    while stack:
        u, sum_path, sum_path_taxes = stack.pop()
        # compute the answer based on sufficient statistics
        answer[u] = taxes[u] * sum_path + sum_path_taxes

        for v, w in tree[u]:
            if previous[u] == v:
                continue
            
            # compute sufficient statistics for the answer for node v
            next_sum_path = sum_path - w * subtreecount[v] + w * (n - subtreecount[v])
            next_sum_path_taxes = sum_path_taxes - w * subtreetaxsum[v] + w * (subtreetaxsum[0] - subtreetaxsum[v])
            stack.append((v, next_sum_path, next_sum_path_taxes))

    print('\n'.join(str(a) for a in answer))

if __name__ == '__main__':
    main()

