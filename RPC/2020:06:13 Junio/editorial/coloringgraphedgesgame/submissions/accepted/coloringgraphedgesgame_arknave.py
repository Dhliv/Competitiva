#!/usr/bin/env python3
from collections import deque

def main():
    n, m = map(int, input().split())
    graph = [[] for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        graph[u].append(v)
        graph[v].append(u)

    dist = [float('inf') for _ in range(n)]
    dist[0] = 0

    q = deque([0])

    while q:
        u = q.popleft()
        for v in graph[u]:
            if dist[u] + 1 < dist[v]:
                dist[v] = dist[u] + 1
                q.append(v)

    print(dist[n - 1] - 1)

if __name__ == '__main__':
    main()
