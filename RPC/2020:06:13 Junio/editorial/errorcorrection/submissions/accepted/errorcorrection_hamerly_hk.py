#!/usr/bin/env python3

import collections
import sys

# solution to errorcorrection, using bipartite matching
#
# - Create a graph like the following, with edges between words that are
#   swappable. These edges represent pairs of words that cannot be in a
#   swap-free set together.
#
# - Determine which nodes have even and odd permutation parity
#   - With this parity concept, the graph is bipartite.
#
# - Find a maximum bipartite matching using the Hopcroft-Karp algorithm
#   - This matching represents the largest group of word pairs that cannot
#     appear together. If there were more word pairs that could be matched, the
#     matching would be larger.
#
# - The largest swap-free set is the number of original words minus the flow in
#   the network (which is the number of matched word pairs).
#
# This version uses Hopcroft-Karp, which should be permissible.

def parity(s):
    '''Define the parity of a sequence as the number of inversions in the
    sequence, which we calculate brute-force. Two words with equal parity
    cannot be swappable; two words with opposing parity may be swappable. Thus
    the two parities form the two sides of our bipartite graph.'''
    p = 0
    for i, c in enumerate(s):
        for j, c2 in enumerate(s[i+1:], i+1):
            if c2 < c:
                p += 1
    return p % 2

oo = 1e100

SINK = None

def bfs(edges, fwd, back, dist):
    frontier = collections.deque()
    for u in fwd:
        if fwd[u] is None:
            dist[u] = 0
            frontier.append(u)
        else:
            dist[u] = oo

    # None here indicates the sink we're looking for
    dist[SINK] = oo

    while frontier:
        u = frontier.popleft()
        if dist[u] < dist[SINK]:
            for v in edges[u]:
                # NB: back[v] could be None, indicating it is an endpoint; or
                # it could be another vertex among those in the starting
                # portion of the graph
                if dist[back[v]] == oo:
                    dist[back[v]] = dist[u] + 1
                    frontier.append(back[v])

    return dist[SINK] != oo

def dfs(edges, u, fwd, back, dist):
    if u == SINK:
        return True

    for v in edges[u]:
        if dist[back[v]] == dist[u] + 1:
            if dfs(edges, back[v], fwd, back, dist):
                fwd[u] = v
                back[v] = u
                return True

    return False

def swap(s, i, j):
    l = list(s)
    l[i], l[j] = l[j], l[i]
    return ''.join(l)

def main():
    n = int(sys.stdin.readline())
    words = [sys.stdin.readline().strip() for _ in range(n)]
    word_index = {w: i for i, w in enumerate(words)}
    edges = {i: [] for i in range(n)}

    # compute the parity of the permutation of each word -- e.g. the parity of
    # the number of inversions are in the string. Connect words that have
    # opposing parity and are one-swap distant.
    parity_words = {0: [], 1: []}
    k = len(words[0])
    for i, w in enumerate(words):
        p = parity(w)
        parity_words[p].append(i)

        # if the parity is 0, then find out if there are any one-swap neighbors
        # that are also in the word list
        if p == 0:
            for a in range(k):
                for b in range(a+1,k):
                    s = swap(w, a, b)
                    if s in word_index:
                        edges[i].append(word_index[s])

    # parings
    fwd = {i: None for i in parity_words[0]}
    back = {i: None for i in parity_words[1]}
    dist = {i: None for i in range(n)}

    # Hopcroft-Karp
    while bfs(edges, fwd, back, dist):
        for u in fwd:
            if fwd[u] is None:
                dfs(edges, u, fwd, back, dist)

    total_flow = sum(v is not None for u, v in fwd.items())
    print(n - total_flow)

if __name__ == '__main__':
    main()

