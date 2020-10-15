#!/usr/bin/env python3

from collections import deque

width=0
height=0 
maze=[]

regionCount = 0


def floodCheck(x, y, q):
    global maze
    if maze[y][x] == 0:
        maze[y][x] = -1
        q.append((x,y))

def floodFill(x0, y0):
    '''Flood-fill any blanks in the maze starting from x,y'''
    global maze
    q = deque([(x0,y0)])
    maze[y0][x0] = -1
    while q:
        (x,y) = q.popleft()
        floodCheck(x+1, y, q);
        floodCheck(x-1, y, q);
        floodCheck(x, y+1, q);
        floodCheck(x, y-1, q);
        y1 = y+1;
        if maze[y1][x] == 1:
            floodCheck(x-1, y1, q)
        elif maze[y1][x] == 2:
            floodCheck(x+1, y1, q)
        ym1 = y-1;
        if maze[ym1][x] == 1:
            floodCheck(x+1, ym1, q)
        elif maze[ym1][x] == 2:
            floodCheck(x-1, ym1, q)

def fillBorderCell(x, y):
    if maze[y][x] == 0:
        floodFill(x,y)
        

def fillBorder():
    global height
    global width
    for y in range(height):
        fillBorderCell(1, y)
        fillBorderCell(width-2, y)
    for x in range(width):
        fillBorderCell(x, 1)
        fillBorderCell(x, height-2)
        
def isADiamond(x, y):
    return maze[y][x] == 1 and maze[y][x+1] == 2 \
        and maze[y+1][x] ==  2 and maze[y+1][x+1] == 1
 
def countRegions():
    global regionCount
    global height
    global width
    
    for y in range(height):
        for x in range(width):
            if maze[y][x] == 0:
                regionCount += 1
                floodFill(x,y)
            elif isADiamond(x,y):
                regionCount += 1
    return regionCount
 

def encodeMaze(c):
    if c == '.':
        return 0
    elif c == '/':
        return 1
    else:
        return 2
    
def main():
    global height
    global width
    global maze
    height, width = map(int, input().split())
    maze.append([-1 for x in range(width+2)])
    for y in range(height):
        line = input()
        row = [-1]
        for x in range(width):
            row.append(encodeMaze(line[x:x+1]))
        row.append(-1)
        maze.append(row)
    maze.append([-1 for x in range(width+2)])

    width += 2
    height += 2

    fillBorder()
    n = countRegions()
    
    print (n)

if __name__ == '__main__':
    main()
