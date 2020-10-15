#!/usr/bin/env python3

n = int(input())
board = [input() for _ in range(n)]

valid = True
for _ in range(2):
    valid = valid and all('BBB' not in row and 'WWW' not in row and row.count('B') == row.count('W') for row in board)
    board = [''.join(row) for row in zip(*board)]

print(1 if valid else 0)
