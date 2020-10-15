try:
    input = raw_input
except NameError:
    pass

TOP, RIGHT, BOTTOM, LEFT = 0, 1, 2, 3

def find(uf, x):
    if x == uf[x]:
        return x
    res = find(uf, uf[x])
    uf[x] = res
    return uf[x]

def merge(uf, x, y):
    xr = find(uf, x)
    yr = find(uf, y)
    if xr == yr:
        return 0
    uf[xr] = yr
    return 1

def main():
    r, c = map(int, input().split())
    maze = [input() for _ in range(r)]

    def node(x, y, z):
        return 4 * (c * x + y) + z

    outside = 4 * r * c
    uf = list(range(outside + 1))
    cc = outside + 1
    for i in range(r):
        for j in range(c):
            if i == 0:
                cc -= merge(uf, node(i, j, TOP), outside)
            elif i == r - 1:
                cc -= merge(uf, node(i, j, BOTTOM), outside)

            if j == 0:
                cc -= merge(uf, node(i, j, LEFT), outside)
            elif j == c - 1:
                cc -= merge(uf, node(i, j, RIGHT), outside)

            if i + 1 < r:
                cc -= merge(uf, node(i, j, BOTTOM), node(i + 1, j, TOP))

            if j + 1 < c:
                cc -= merge(uf, node(i, j, RIGHT), node(i, j + 1, LEFT))

            if maze[i][j] == '/' or maze[i][j] == '.':
                cc -= merge(uf, node(i, j, LEFT), node(i, j, TOP))
                cc -= merge(uf, node(i, j, BOTTOM), node(i, j, RIGHT))

            if maze[i][j] == '\\' or maze[i][j] == '.':
                cc -= merge(uf, node(i, j, LEFT), node(i, j, BOTTOM))
                cc -= merge(uf, node(i, j, TOP), node(i, j, RIGHT))

    print(cc - 1)

if __name__ == '__main__':
    main()
