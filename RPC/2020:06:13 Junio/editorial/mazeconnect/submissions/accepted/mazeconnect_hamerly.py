#!/usr/bin/env python2

import sys

# coordinate system -- walls are at (i,j) coordinates, in between them are cells
#   and we use above(i,j) or below(i,j) to refer to neighbors
#
#  0123456789
# 0/\/\/\/\/\ between rows 0/1: cells (0,0), (0,1), ..., (0,c//2)
# 1\/\/\/\/\/
# 2/\/\/\/\/\ between rows 1/2: cells (1,0), (1,1), ..., (1,c//2-1)
# 3\/\/\/\/\/
#
# If the maze uses the alternate coordinate system, then pad it at the top.
# Also, pad the bottom if the number of rows is odd.


def even(x): return (x % 2) == 0
def odd(x): return not even(x)

def above(i, j):
    if even(i+j): # should be "/" or "."
        return (i-1, (j-1) // 2)
    else: # should be "\" or "."
        return (i-1, j // 2)

def below(i, j):
    if even(i+j): # should be "/" or "."
        return (i, j // 2)
    else: # should be "\" or "."
        return (i, (j-1) // 2)

class DisjointSet(object):
    '''Disjoint set of adjustable size, where each key is an
    arbitrary hashable object.'''

    def __init__(self):
        self.parent = []
        self.size = []
        self.lut = {}

    def _add(self, x):
        assert x not in self.lut
        n = len(self.lut)
        self.parent.append(n)
        self.size.append(1)
        self.lut[x] = n
        return n

    def lookup(self, x):
        if x in self.lut:
            return self.lut[x]
        return self._add(x)

    def find(self, x):
        s = [self.lookup(x)]
        while self.parent[s[-1]] != s[-1]:
            s.append(self.parent[s[-1]])
        for c in s:
            self.parent[c] = s[-1]
        return s[-1]

    def join(self, x, y):
        px = self.find(x)
        py = self.find(y)
        if px != py:
            if self.size[py] < self.size[px]:
                px, py = py, px
            self.parent[px] = py
            self.size[py] += self.size[px]

    def __repr__(self):
        '''debugging'''
        groups = {}
        for x in self.lut:
            r = self.find(x)
            print(x, self.lut[x], r, self.parent[self.lut[x]])
            if r not in groups:
                groups[r] = {'size': 0, 'members': []}
            groups[r]['members'].append(x)
            groups[r]['size'] += 1
        return str(groups)

    def num_groups(self):
        return len({self.find(x) for x in self.lut})


def fix_maze(maze):
    # force the maze to fit into our coordinate system by padding the top, and
    # extending the bottom if necessary

    r = len(maze)
    c = len(maze[0])

    # figure out which of the two types of mazes we have
    our_coordinate_system = None
    for i in range(r):
        for j in range(c):
            if maze[i][j] != '.':
                our_coordinate_system = ((i + j) % 2 == 1) ^ (maze[i][j] == '/')
                break
        if our_coordinate_system is not None:
            break

    if not our_coordinate_system:
        maze = ['.' * c] + maze
        r += 1

    if odd(len(maze)):
        maze = maze + ['.' * c]
        r += 1

    return maze, r, c

def main():
    r, c = tuple(map(int, sys.stdin.readline().split()))

    maze = [sys.stdin.readline().strip() for _ in range(r)]

    maze, r, c = fix_maze(maze)

    OUTSIDE = 'outside'
    ds = DisjointSet()
    ds.lookup(OUTSIDE)

    # do the outside edges left and right
    cols = [(0, odd), (c-1, even)]
    for i in range(r):
        for col, test in cols:
            inside = above(i, col) if test(i+col) else below(i, col)
            ds.lookup(inside)
            if maze[i][col] == '.':
                ds.join(inside, OUTSIDE)

    # do the outside edges top and bottom
    rows = [(0, below), (r-1, above)]
    for j in range(c):
        for row, neighbor in rows:
            inside = neighbor(row, j)
            ds.lookup(inside)
            if maze[row][j] == '.':
                ds.join(inside, OUTSIDE)

    # do all the internal walls
    for i in range(1, r-1):
        for j in range(1, c-1):
            a, b = above(i, j), below(i, j)
            ds.lookup(a)
            ds.lookup(b)
            if maze[i][j] == '.':
                ds.join(a, b)

    # the number of walls to knock down is the number of groups we made, minus
    # one (since we need to end up with one group)
    print(ds.num_groups() - 1)

if __name__ == '__main__':
    main()

