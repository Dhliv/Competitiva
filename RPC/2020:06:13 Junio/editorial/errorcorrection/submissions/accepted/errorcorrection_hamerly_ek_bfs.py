#!/usr/bin/env python2

import collections
import sys

# solution to errorcorrection, using bipartite matching
#
# - Create a graph like the following, with edges between words that are
#   swappable. These edges represent pairs of words that cannot be in a
#   swap-free set together.
#
# - Add a source and a sink, connecting the source to those nodes with "even"
#   permutation parity, and the sink to those with "odd" permutation parity.
#   - With this parity concept, the graph is bipartite.
#
# - Find a maximum bipartite matching using the Edmonds-Karp algorithm (Ford
#   Fulkerson with BFS).
#   - This matching represents the largest group of word pairs that cannot
#     appear together. If there were more word pairs that could be matched, the
#     matching would be larger.
#
# - The largest swap-free set is the number of original words minus the flow in
#   the network (which is the number of matched word pairs).
#
# Runtime: O(V^2 + VE^2), where V = n = number of words, and E <= V^2, so
# overall O(V^5), which is too slow. However, in reality E <= 325 * V (since
# any one word can have at most 325 = (26 * 25 / 2) edges), so it's closer to
# O(V^4) with a large constant.

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

SOURCE = 0
SINK = 1

def bfs(flow):
    '''Use BFS to find a path with remaining flow in the network from SOURCE to
    SINK, if one exists.'''

    global SOURCE, SINK

    frontier = collections.deque([SOURCE])
    back_links = {SOURCE: -1}

    while frontier and SINK not in back_links:
        current = frontier.popleft()

        for neighbor, f in flow[current].items():
            if f == 1 or neighbor in back_links:
                continue
            frontier.append(neighbor)
            back_links[neighbor] = current

    if SINK in back_links:
        path = []
        node = SINK
        while node in back_links:
            path.append(node)
            node = back_links[node]

        return list(reversed(path))

    return []
def swap(s, i, j):
    l = list(s)
    l[i], l[j] = l[j], l[i]
    return ''.join(l)

def main():
    n = int(sys.stdin.readline())
    words = [sys.stdin.readline().strip() for _ in range(n)]
    word_index = {w: i for i, w in enumerate(words)}
    # NB: source = 0, sink = 1
    edges = {i: [] for i in range(n+2)}

    # compute the parity of the permutation of each word -- e.g. the parity of
    # the number of inversions are in the string. Two words can 
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
                        edges[i+2].append(word_index[s]+2) # NB: +2 for SOURCE and SINK

    for i in parity_words[0]:
        edges[SOURCE].append(i+2) # NB: +2 for SOURCE and SINK
    for i in parity_words[1]:
        edges[i+2].append(SINK)

    if 1 < len(sys.argv):
        print('digraph G {')
        for u in edges:
            if 2 <= u:
                color = 'green' if (u - 2) in parity_words[0] else 'red'
                print('{} [label={},style=filled,fillcolor={}];'.format(u, words[u-2], color))
            for v in edges[u]:
                print("{} -> {};".format(u, v))
        print('};')
        return

    flow = {u: {} for u in edges}
    for u in edges:
        for v in edges[u]:
            flow[u][v] = 0
            flow[v][u] = 1

    # Edmonds-Karp
    while True:
        path = bfs(flow)
        if not path:
            break

        for i in range(len(path) - 1):
            a, b = path[i:i+2]
            flow[a][b] += 1
            flow[b][a] -= 1

    total_flow = sum(flow[0].values())
    print(n - total_flow)

if __name__ == '__main__':
    main()

