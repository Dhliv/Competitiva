permutations = [[1, 2, 3], [1, 3, 2], [2, 3, 1], [2, 1, 3], [3, 1, 2], [3, 2, 1]]
orders = [[0, 0, 0], [0, 0, 1], [0, 1, 0], [1, 0, 0], [1, 1, 0], [0, 1, 1], [1, 0, 1], [1, 1, 1]]

n = int(input())

for i in range(n):

    a1, b1, a2, b2, a3, b3 = [int(x) for x in input().split()]

    rects = [(a1, b1), (a2, b2), (a3, b3)]
    minima = 9223372036854775807
    f = False
    for permutation in permutations:
        for order in orders:
            rect1 = rects[permutation[0] - 1]
            rect2 = rects[permutation[1] - 1]
            rect3 = rects[permutation[2] - 1]

            if order[0] == 1:
                rect1 = (rect1[1], rect1[0])
            if order[1] == 1:
                rect2 = (rect2[1], rect2[0])
            if order[2] == 1:
                rect3 = (rect3[1], rect3[0])

            area1 = (max(rect1[0], rect2[0]) + rect3[0]) * (max(rect1[1], rect3[1]) + rect2[1])
            area2 = max(rect1[0], rect2[0] + rect3[0]) * (rect1[1] + max(rect2[1], rect3[1]))
            area3 = max(rect1[0], rect2[0], rect3[0]) * (rect1[1] + rect2[1] + rect3[1])
            minima = min(area1, min(area2, min(area3, minima)))

    print(minima)
