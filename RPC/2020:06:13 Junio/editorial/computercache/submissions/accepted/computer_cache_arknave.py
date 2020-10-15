from __future__ import division, print_function
import sys

def fenwick_query(tree, idx):
    idx += 1
    res = 0
    while idx > 0:
        res += tree[idx - 1]
        idx -= (idx & -idx)
    return res

def fenwick_update(tree, idx, delta):
    idx += 1
    while idx <= len(tree):
        tree[idx - 1] += delta
        idx += (idx & -idx)

class LazySegTree(object):
    def __init__(self, n):
        self.n = n
        self.data = [-1 for _ in range(4 * n)]

    def push(self, node):
        if self.data[node] != -1:
            self.data[2 * node] = self.data[node]
            self.data[2 * node + 1] = self.data[node]
            self.data[node] = -1

    def _query(self, node, l, r, idx):
        if l == r:
            # assert l == idx
            return self.data[node]

        self.push(node)

        mid = (l + r) // 2
        if idx <= mid:
            return self._query(2 * node, l, mid, idx)
        else:
            return self._query(2 * node + 1, mid + 1, r, idx)

    def query(self, idx):
        return self._query(1, 0, self.n - 1, idx)

    def _range_set(self, node, l, r, ql, qr, v):
        if qr < l or r < ql:
            return

        if ql <= l and r <= qr:
            self.data[node] = v
            return

        self.push(node)

        mid = (l + r) // 2
        self._range_set(2 * node, l, mid, ql, qr, v)
        self._range_set(2 * node + 1, mid + 1, r, ql, qr, v)

    def range_set(self, l, r, v):
        self._range_set(1, 0, self.n - 1, l, r, v)

def main():
    all_data = sys.stdin.read().split('\n')
    n, m, q = map(int, all_data[0].split())
    s = [list(map(int, all_data[i].split()[1:])) for i in range(1, m + 1)]

    # note EVERYTHING is 0-indexed
    queries = [list(map(lambda x: int(x) - 1, all_data[i].split())) for i in range(m + 1, q + m + 1)]

    # Solution strategy:
    # Process all the queries twice.

    # On the first go-around, figure out which load query is responsible for
    # each print query. Ignore all the range increment updates.

    # On the second go-around, immediately after a load, answer all the print
    # queries. Handle range increment updates using a BIT.

    # Runtime: O(q log n), but probably a big constant factor
    fenwick_trees = [[0 for x in r] for r in s]
    cache = LazySegTree(n)
    by_load = [[] for _ in queries]
    ans = [0 for _ in queries]

    for idx, query in enumerate(queries):
        op = query[0]
        if op == 0:
            # Load data into cache. This means we'll do a range set on this range
            # in the cache to this query ID
            i, p = query[1:]
            cache.range_set(p, p + len(s[i]) - 1, idx)
        elif op == 1:
            # Print query. Query the cache to figure out where this belongs.
            load_idx = cache.query(query[1])
            if load_idx >= 0:
                by_load[load_idx].append(idx)
        else:
            # assert op == 2
            # increment query. Ignore for now.
            pass

    for idx, query in enumerate(queries):
        op = query[0]
        if op == 0:
            # Don't need to actually move data, just process all the print statements
            i, p = query[1:]
            for print_idx in by_load[idx]:
                d = queries[print_idx][1] - query[2]
                val = s[i][d] + fenwick_query(fenwick_trees[i], d)
                val &= 0xff
                ans[print_idx] = val
        elif op == 1:
            # We're processing these immediately after their loads. Ignore here.
            pass
        else:
            # assert op == 2
            _, i, l, r = query
            fenwick_update(fenwick_trees[i], l, 1)
            fenwick_update(fenwick_trees[i], r + 1, -1)

    out = []
    for idx, query in enumerate(queries):
        if query[0] == 1:
            out.append(str(ans[idx]))

    print('\n'.join(out))

if __name__ == '__main__':
    main()
